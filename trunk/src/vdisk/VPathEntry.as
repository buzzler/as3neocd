package vdisk
{
	public class VPathEntry
	{
		public	var id					:String;
		public	var parent_dir_num		:uint;
		public	var location			:uint;
		public	var ext_attr_rec_length	:uint;
		public	var directory			:VDirectory;
	}
}