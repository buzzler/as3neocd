package
{
	public class Util
	{
		public	static function swab( src1:Vector.<uint>, offset1:uint, src2:Vector.<uint>, offset2:uint, isize:int):void
		{
			var tmp:uint;
			for (var ic:uint=0 ; ic<isize ; ic+=2)
			{
				tmp = src1[offset1+ic];
				src2[offset2+ic] = src1[offset1+ic+1];
				src2[offset2+ic+1] = tmp;
			}
		}
		
		public	static function calloc(size:uint, count:uint, value:uint = 0):Vector.<uint>
		{
			var length:uint = size*count;
			var result:Vector.<uint> = new Vector.<uint>(length, true);
			for (var i:int=0 ; i < length ; i++)
			{
				result[i] = value;
			}
			return result;
		}
		
		public	static function memcpy( dest:Vector.<uint>, offsetDst:uint, src:Vector.<uint>, offsetSrc:uint, size:uint):void
		{
			for (var i:uint = 0 ; i < size ; i++)
			{
				dest[offsetDst+i] = src[offsetSrc+i];
			}
		}
		
		public	static function memset( dest:Vector.<uint>, offset:uint, value:uint, num:uint):Vector.<uint>
		{
			for (var i:uint = 0 ; i < num ; i++)
			{
				dest[offset+i] = value;
			}
			return dest;
		}
		
		public	static function toVector(array:Array, type:String, fixed:Boolean = false):*
		{
			var result:*;
			switch (type)
			{
				case "uint":
					result = new Vector.<uint>(array.length, fixed);
					break;
				case "number":
					result = new Vector.<Number>(array.length, fixed);
					break;
				case "function":
					result = new Vector.<Function>(array.length, fixed);
					break;
				case "string":
					result = new Vector.<String>(array.length, fixed);
					break;
			}
			var i:uint = 0;
			var total:uint = array.length;
			while (i<total)
			{
				result[i] = array[i++];
			}
			return result;
		}
	}
}