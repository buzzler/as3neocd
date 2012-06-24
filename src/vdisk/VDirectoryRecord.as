package vdisk
{
	import flash.utils.ByteArray;

	public class VDirectoryRecord
	{
		public	var record_length			:uint;
		public	var ext_attr_rec_length		:uint;
		public	var location				:uint;
		public	var data_length				:uint;
		public	var year					:uint;
		public	var month					:uint;
		public	var day						:uint;
		public	var hour					:uint;
		public	var minute					:uint;
		public	var second					:uint;
		public	var GMT						:int;
		public	var file_flag				:uint;
		public	var file_unit_size			:uint;
		public	var interleave_gap_size		:uint;
		public	var volume_sequence_number	:uint;
		public	var file_id					:String;
	}
}