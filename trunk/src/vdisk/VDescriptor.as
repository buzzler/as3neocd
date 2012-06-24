package vdisk
{
	import flash.utils.ByteArray;

	public class VDescriptor
	{
		public	static const TYPE_EMPTY	:uint = 0x00;	// Boot Record
		public	static const TYPE_PVD	:uint = 0x01;	// Primary Volume Descriptor
		public	static const TYPE_SVD	:uint = 0x02;	// Supplementary Volume Descriptor
		public	static const TYPE_VPD	:uint = 0x03;	// Volume Partition Descriptor
		public	static const TYPE_VDST	:uint = 0xFF;	// Volume Descriptor Set Terminator
		
		public	var type					:uint;
		public	var id						:String;
		public	var version					:uint;
		public	var system_id				:String;
		public	var volume_id				:String;
		public	var volume_space_size		:uint;
		public	var volume_set_size			:uint;
		public	var volume_sequence_number	:uint;
		public	var logical_block_size		:uint;
		public	var path_table_size			:uint;
		public	var location_1st_path_table	:uint;
		public	var location_2nd_path_table	:uint;
		
		public function VDescriptor(pointer:ByteArray, offset:uint)
		{
			pointer.position = offset;
			var type:uint = pointer.readUnsignedByte();
			switch (type)
			{
				case TYPE_EMPTY:
					break;
				case TYPE_PVD:
					parsePVD(pointer, offset);
					break;
				case TYPE_SVD:
					parseSVD(pointer, offset);
					break;
				case TYPE_VPD:
					parseVPD(pointer, offset);
					break;
				case TYPE_VDST:
					parseVDST(pointer, offset);
					break;
			}
		}
		
		private	function parsePVD(pointer:ByteArray, offset:uint):void
		{
			const ASCII:String				= "us-ascii";
			pointer.position				= offset;
			this.type						= pointer.readUnsignedByte();
			this.id							= pointer.readMultiByte(5, ASCII);
			this.version					= pointer.readUnsignedByte();
			
			pointer.position				= offset+8;
			this.system_id					= pointer.readMultiByte(32, ASCII);
			this.volume_id					= pointer.readMultiByte(32, ASCII);
			
			pointer.position				= offset+84;
			this.volume_space_size			= pointer.readUnsignedInt();
			
			pointer.position				= offset+122;
			this.volume_set_size			= pointer.readUnsignedByte()<<8 | pointer.readUnsignedByte();
			
			pointer.position				= offset+126;
			this.volume_sequence_number		= pointer.readUnsignedByte()<<8 | pointer.readUnsignedByte();
			
			pointer.position				= offset+130;
			this.logical_block_size			= pointer.readUnsignedByte()<<8 | pointer.readUnsignedByte();
			
			pointer.position				= offset+136;
			this.path_table_size			= pointer.readUnsignedInt();
			
			pointer.position				= offset+148;
			this.location_1st_path_table	= pointer.readUnsignedInt();
			this.location_2nd_path_table	= pointer.readUnsignedInt();
		}
		
		private	function parseSVD(pointer:ByteArray, offset:uint):void
		{
			pointer.position = offset;
			this.type = pointer.readUnsignedByte();
		}
		
		private	function parseVPD(pointer:ByteArray, offset:uint):void
		{
			pointer.position = offset;
			this.type = pointer.readUnsignedByte();
		}
		
		private	function parseVDST(pointer:ByteArray, offset:uint):void
		{
			pointer.position = offset;
			this.type = pointer.readUnsignedByte();
		}
	}
}