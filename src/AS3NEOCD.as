package
{
	import flash.display.Bitmap;
	import flash.display.Sprite;
	import flash.display.StageAlign;
	import flash.display.StageScaleMode;
	import flash.events.DataEvent;
	import flash.events.Event;
	import flash.events.HTTPStatusEvent;
	import flash.events.MouseEvent;
	import flash.media.Sound;
	import flash.net.FileFilter;
	import flash.net.FileReference;
	import flash.net.FileReferenceList;
	import flash.text.TextField;
	import flash.text.TextFieldAutoSize;
	import flash.utils.ByteArray;
	
	[SWF(width="400", height="300", frameRate="30", backgroundColor="0xFFFFFF")]
	public class AS3NEOCD extends Sprite
	{
		[Embed(source="../essential/NEOCD.BIN", mimeType="application/octet-stream")]
		public	var BIOS:Class;
		[Embed(source="../essential/STARTUP.BIN", mimeType="application/octet-stream")]
		public	var STARTUP:Class;
		[Embed(source="../essential/MEMCARD.BIN", mimeType="application/octet-stream")]
		public	var MEMCARD:Class;
		[Embed(source="../essential/LOADING.PNG", mimeType="image/png")]
		public	var LOADING:Class;
		
		[Embed(source="../iso/metal slug/Metal Slug - Track 02.mp3", mimeType="application/octet-stream")]
		public	var TRACK02:Class;
		[Embed(source="../iso/metal slug/Metal Slug - Track 03.mp3", mimeType="application/octet-stream")]
		public	var TRACK03:Class;
		[Embed(source="../iso/metal slug/Metal Slug - Track 04.mp3", mimeType="application/octet-stream")]
		public	var TRACK04:Class;
		[Embed(source="../iso/metal slug/Metal Slug - Track 05.mp3", mimeType="application/octet-stream")]
		public	var TRACK05:Class;
		[Embed(source="../iso/metal slug/Metal Slug - Track 06.mp3", mimeType="application/octet-stream")]
		public	var TRACK06:Class;
		[Embed(source="../iso/metal slug/Metal Slug - Track 07.mp3", mimeType="application/octet-stream")]
		public	var TRACK07:Class;
		[Embed(source="../iso/metal slug/Metal Slug - Track 08.mp3", mimeType="application/octet-stream")]
		public	var TRACK08:Class;
		[Embed(source="../iso/metal slug/Metal Slug - Track 09.mp3", mimeType="application/octet-stream")]
		public	var TRACK09:Class;
		[Embed(source="../iso/metal slug/Metal Slug - Track 10.mp3", mimeType="application/octet-stream")]
		public	var TRACK10:Class;
		[Embed(source="../iso/metal slug/Metal Slug - Track 11.mp3", mimeType="application/octet-stream")]
		public	var TRACK11:Class;
		[Embed(source="../iso/metal slug/Metal Slug - Track 12.mp3", mimeType="application/octet-stream")]
		public	var TRACK12:Class;
		[Embed(source="../iso/metal slug/Metal Slug - Track 13.mp3", mimeType="application/octet-stream")]
		public	var TRACK13:Class;
		[Embed(source="../iso/metal slug/Metal Slug - Track 14.mp3", mimeType="application/octet-stream")]
		public	var TRACK14:Class;
		[Embed(source="../iso/metal slug/Metal Slug - Track 15.mp3", mimeType="application/octet-stream")]
		public	var TRACK15:Class;
		[Embed(source="../iso/metal slug/Metal Slug - Track 16.mp3", mimeType="application/octet-stream")]
		public	var TRACK16:Class;
		[Embed(source="../iso/metal slug/Metal Slug - Track 17.mp3", mimeType="application/octet-stream")]
		public	var TRACK17:Class;
		[Embed(source="../iso/metal slug/Metal Slug - Track 18.mp3", mimeType="application/octet-stream")]
		public	var TRACK18:Class;
		[Embed(source="../iso/metal slug/Metal Slug - Track 19.mp3", mimeType="application/octet-stream")]
		public	var TRACK19:Class;
		[Embed(source="../iso/metal slug/Metal Slug - Track 20.mp3", mimeType="application/octet-stream")]
		public	var TRACK20:Class;
		
		
		public	var neocd:NeocdCore;
		public	var tf:TextField;
		
		public function AS3NEOCD()
		{
			super();
			stage.scaleMode = StageScaleMode.NO_SCALE;
			stage.align = StageAlign.TOP_LEFT;
			
			neocd = new NeocdCore(new LOADING());
			neocd.disk.cachFile("NEOCD.BIN", new BIOS());
			neocd.disk.cachFile("STARTUP.BIN", new STARTUP());
			neocd.disk.cachFile("MEMCARD.BIN", new MEMCARD());
			neocd.disk.insertTrack(new TRACK02() as Sound);
			neocd.disk.insertTrack(new TRACK03() as Sound);
			neocd.disk.insertTrack(new TRACK04() as Sound);
			neocd.disk.insertTrack(new TRACK05() as Sound);
			neocd.disk.insertTrack(new TRACK06() as Sound);
			neocd.disk.insertTrack(new TRACK07() as Sound);
			neocd.disk.insertTrack(new TRACK08() as Sound);
			neocd.disk.insertTrack(new TRACK09() as Sound);
			neocd.disk.insertTrack(new TRACK10() as Sound);
			neocd.disk.insertTrack(new TRACK11() as Sound);
			neocd.disk.insertTrack(new TRACK12() as Sound);
			neocd.disk.insertTrack(new TRACK13() as Sound);
			neocd.disk.insertTrack(new TRACK14() as Sound);
			neocd.disk.insertTrack(new TRACK15() as Sound);
			neocd.disk.insertTrack(new TRACK16() as Sound);
			neocd.disk.insertTrack(new TRACK17() as Sound);
			neocd.disk.insertTrack(new TRACK18() as Sound);
			neocd.disk.insertTrack(new TRACK19() as Sound);
			neocd.disk.insertTrack(new TRACK20() as Sound);
			neocd.x = (stage.stageWidth-neocd.width)/2;
			neocd.y = (stage.stageHeight-neocd.height)/2;
			addChild(neocd);
			
			tf = new TextField();
			tf.autoSize = TextFieldAutoSize.LEFT;
			tf.htmlText = "<B>AS3NEOCD</B> (buzzler@buzzler.pe.kr)";
			tf.selectable = false;
			tf.x = stage.stageWidth-tf.width;
			tf.y = stage.stageHeight-tf.height;
			addChild(tf);
			
			tf = new TextField();
			tf.autoSize = TextFieldAutoSize.LEFT;
			tf.htmlText = "CDDA";
			tf.selectable = false;
			tf.x = 0;
			tf.y = 0;
			tf.addEventListener(MouseEvent.CLICK, onClickCDDA);
			addChild(tf);
			
			tf = new TextField();
			tf.autoSize = TextFieldAutoSize.LEFT;
			tf.htmlText = "CDROM";
			tf.selectable = false;
			tf.x = 40;
			tf.y = 0;
			tf.addEventListener(MouseEvent.CLICK, onClickCDROM);
			addChild(tf);
		}
		
		protected function onClickCDROM(event:MouseEvent):void
		{
			var fp:FileReference = new FileReference();
			fp.addEventListener(Event.SELECT, function (event:Event):void{
				fp.addEventListener(Event.COMPLETE, function (event:Event):void {
					neocd.disk.insertIso(fp.data);
					neocd.power();
				});
				fp.load();
			});
			fp.browse([new FileFilter("ISO9660 Image", "iso")]);
		}
		
		protected function onClickCDDA(event:MouseEvent):void
		{
			;
		}
		
		private	function onClick(event:MouseEvent):void
		{

		}
	}
}