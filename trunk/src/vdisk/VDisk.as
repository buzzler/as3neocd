package vdisk
{
	import flash.media.Sound;
	import flash.ui.Keyboard;
	import flash.utils.ByteArray;

	public class VDisk
	{
		private	var _tracks		:Vector.<Sound>;
		private	var _cach		:Object;
		private	var _iso		:ByteArray;
		private	var _descriptors:Vector.<VDescriptor>;
		private	var _pvd		:VDescriptor;
		private	var _paths1		:VPathTable;
		private	var _paths2		:VPathTable;
		
		public function VDisk()
		{
			_tracks = new Vector.<Sound>();
			_cach = new Object();
			_descriptors = new Vector.<VDescriptor>();
			_pvd = null;
		}
		
		public	function cachFile(filename:String, rom:ByteArray):void
		{
			_cach[filename.toUpperCase()] = rom;
		}
		
		public	function getIso():ByteArray
		{
			return _iso;
		}
		
		public	function insertIso(iso:ByteArray):void
		{
			_iso = iso;
			var offset:uint = 2048*16;
			while (true)
			{
				if (iso.bytesAvailable==0)
				{
					break;
				}
				
				var descriptor:VDescriptor = new VDescriptor(iso, offset);
				_descriptors.push(descriptor);
				
				if (descriptor.type==VDescriptor.TYPE_PVD)
				{
					_pvd = descriptor;
				}
				else if (descriptor.type==VDescriptor.TYPE_VDST)
				{
					break;
				}
				
				offset+=2048;
			}

			var entry:VPathEntry;
			
			if (_pvd.location_1st_path_table > 0)
			{
				offset = _pvd.logical_block_size * _pvd.location_1st_path_table;
				_paths1 = new VPathTable(iso, offset);

				for each (entry in _paths1.entries)
				{
					offset = _pvd.logical_block_size * entry.location;
					entry.directory = new VDirectory(iso, offset, _pvd.logical_block_size);
				}
			}
			
			if (_pvd.location_2nd_path_table > 0)
			{
				offset = _pvd.logical_block_size * _pvd.location_2nd_path_table;
				_paths2 = new VPathTable(iso, offset);
				
				for each (entry in _paths2.entries)
				{
					offset = _pvd.logical_block_size * entry.location;
					entry.directory = new VDirectory(iso, offset, _pvd.logical_block_size);
				}
			}
		}
		
		public	function openFile(filename:String):ByteArray
		{
			var result:ByteArray = new ByteArray();
			var root:VPathEntry = _paths1.getEntry("ROOT");
			if (root==null)
			{
				return result;
			}
			var record:VDirectoryRecord = root.directory.getRecord(filename);
			if (record==null)
			{
				var rom:ByteArray = _cach[filename.toUpperCase()] as ByteArray;
				return (rom!=null) ? rom:result;
			}
			
			_iso.position = _pvd.logical_block_size * record.location;
			_iso.readBytes(result,0,record.data_length);
			
			return result;
		}
		
		public	function closeFile(dest:ByteArray):void
		{
			dest.clear();
		}
		
		public	function readFile(dest:Vector.<uint>, offset:uint, size:uint, count:uint, src:ByteArray):int
		{
			var i:int;
			try
			{
				if (size==1)
				{
					for (i = 0 ; i < count ; i++)
					{
						dest[offset+i] = src.readUnsignedByte();
					}
				}
				else if (size==2)
				{
					for (i = 0 ; i < count ; i++)
					{
						dest[offset+i] = src.readUnsignedByte()<<8 | src.readUnsignedByte();
					}
				}
				else if (size==4)
				{
					for (i = 0 ; i < count ; i++)
					{
						dest[offset+i] = src.readUnsignedInt();
					}
				}
			}
			catch (error:Error)
			{
			}
			return i;
		}
		
		public	function writeFile(src:Vector.<uint>, offset:uint, size:uint, count:uint, dest:ByteArray):int
		{
			var i:int;
			try
			{
				if (size==1)
				{
					for (i = 0 ; i < count ; i++)
					{
						dest.writeByte( src[offset+i] );
					}
				}
				else if (size==2)
				{
					for (i = 0 ; i < count ; i++)
					{
						dest.writeShort( src[offset+i] );
					}
				}
				else if (size==4)
				{
					for (i = 0 ; i < count ; i++)
					{
						dest.writeUnsignedInt( src[offset+i] );
					}
				}
			}
			catch (error:Error)
			{
			}
			return i;
		}
		
		public	function getString(num:uint, src:ByteArray):String
		{
			var result:String = "";
			var current:uint = src.position;
			var lb:Number = '\n'.charCodeAt(0);
			
			while (true)
			{
				var c:uint = src[current++] as uint;
				if (c == lb)
				{
					break;
				}
			}
			
			return src.readMultiByte(current-src.position, "us-ascii");
		}
		
		public	function insertTracks(tracks:Vector.<Sound>):void
		{
			_tracks.length = 0;
			for each (var sound:Sound in tracks)
			{
				_tracks.push(sound);
			}
		}
		
		public	function insertTrack(track:Sound):void
		{
			_tracks.push(track);
		}
		
		public	function numTracks():uint
		{
			return _tracks.length;
		}
		
		public	function openTracks():Vector.<Sound>
		{
			return _tracks;
		}
		
		public	function openTrack(number:uint):Sound
		{
			return _tracks[number-2];
		}
	}
}