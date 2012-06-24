package vdisk
{
	import flash.utils.ByteArray;

	public class VDirectory
	{
		public	var records:Vector.<VDirectoryRecord>;
		public	var hash:Object;
		
		public function VDirectory(pointer:ByteArray, offset:uint, blocks:uint = 2048)
		{
			records = new Vector.<VDirectoryRecord>();
			hash = new Object();
			
			pointer.position = offset;
			var dirs:int = 1;
			while (true)
			{
				var length:uint = pointer.readUnsignedByte();
				if (length==0)
				{
					break;
				}
				else
				{
					var record:VDirectoryRecord = new VDirectoryRecord();
					record.record_length		= length;
					record.ext_attr_rec_length	= pointer.readUnsignedByte();
					
					pointer.position += 4;
					record.location				= pointer.readUnsignedInt();
					
					pointer.position += 4;
					record.data_length			= pointer.readUnsignedInt();
					record.year					= pointer.readUnsignedByte();
					record.month				= pointer.readUnsignedByte();
					record.day					= pointer.readUnsignedByte();
					record.hour					= pointer.readUnsignedByte();
					record.minute				= pointer.readUnsignedByte();
					record.second				= pointer.readUnsignedByte();
					record.GMT					= pointer.readByte();
					record.file_flag			= pointer.readUnsignedByte();
					record.file_unit_size		= pointer.readUnsignedByte();
					record.interleave_gap_size	= pointer.readUnsignedByte();
					
					pointer.position += 2;
					record.volume_sequence_number=pointer.readUnsignedByte()<<8 | pointer.readUnsignedByte();
					var n:uint					= pointer.readUnsignedByte()
					record.file_id				= pointer.readMultiByte(n, "us-ascii");
					record.file_id				= (record.file_id.indexOf(';') >= 0) ? record.file_id.substr(0, record.file_id.indexOf(';')):record.file_id;
					
					if (n%2==0)
					{
						pointer.position++;
					}
					
					records.push(record);
					hash[record.file_id.toUpperCase()] = record;
					
					if (blocks-pointer.position%blocks < 34)
					{
						pointer.position = offset+dirs*blocks;
						dirs++;
					}
				}
			}
		}
		
		public	function getRecord(filename:String):VDirectoryRecord
		{
			return hash[filename] as VDirectoryRecord;
		}
	}
}