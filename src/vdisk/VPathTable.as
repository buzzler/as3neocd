package vdisk
{
	import flash.utils.ByteArray;

	public class VPathTable
	{
		public	var entries	:Vector.<VPathEntry>;
		public	var hash	:Object;
		
		public function VPathTable(pointer:ByteArray, offset:uint):void
		{
			entries = new Vector.<VPathEntry>();
			hash = new Object();
			
			const ASCII:String = "us-ascii";
			pointer.position = offset;
			while (true)
			{
				var id_length:uint = pointer.readUnsignedByte();
				if (id_length<=0)
				{
					break;
				}
				else
				{
					var entry:VPathEntry		= new VPathEntry();
					entry.ext_attr_rec_length	= pointer.readUnsignedByte();
					entry.location				= pointer.readUnsignedInt();
					entry.parent_dir_num		= pointer.readUnsignedByte()<<8 | pointer.readUnsignedByte();
					entry.id					= pointer.readMultiByte(id_length, ASCII);
					
					if (pointer.position%2>0)
					{
						pointer.position++;
					}
					if (entry.id.length==0)
					{
						entry.id = "ROOT";
					}
					
					entries.push(entry);
					hash[entry.id.toUpperCase()] = entry;
				}
			}
		}
		
		public	function getEntry(id:String):VPathEntry
		{
			return hash[id] as VPathEntry;
		}
	}
}