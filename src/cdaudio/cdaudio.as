import flash.events.Event;
import flash.media.Sound;
import flash.media.SoundChannel;
import flash.media.SoundMixer;

/**
 * CUSTOM VARIABLES
 */
private	var soundTrack		:Sound;
private	var soundChannel	:SoundChannel;
private	var soundPosition	:Number;

public	var cdda_first_drive	:int;
public	var cdda_nb_of_drives	:int;
public	var	cdda_current_drive	:int;
public	var cdda_current_track	:int;
public	var cdda_current_frame	:int;
public	var cdda_playing		:Boolean;
public	var	cdda_autoloop		:Boolean;
public	var cdda_volume			:int;
public	var cdda_disabled		:Boolean;

private	var cdda_min_track		:int;
private	var cdda_max_track		:int;
private	var cdda_disk_length	:int;

private	function cdda_init():Boolean
{
	cdda_min_track = cdda_max_track = 0;
	cdda_current_track = 0;
	cdda_playing = false;
	
	if (disk.numTracks()==0)
	{
		trace("Couldn't open drive for audio.");
		cdda_disabled = true;
	}
	else
	{
		cdda_get_disk_info();
		cdda_disabled = false;
		trace("CD Audio OK!");
	}
	return true;
}

private	function cdda_get_disk_info():Boolean
{
	if (cdda_disabled==true)
	{
		return true;
	}
	
	if( disk.numTracks() > 0 )
	{
		cdda_min_track		= 0;
		cdda_max_track		= disk.numTracks();
		cdda_disk_length	= disk.numTracks();
	}
	else
	{
		trace("Error: No Disc in drive");
		cdda_disabled = true;
	}
	return true;
}

private	function cdda_play(track:int):Boolean
{
	if (cdda_disabled==true)
	{
		return true;
	}
	
	if (cdda_playing && cdda_current_track==track)
	{
		return true;
	}
	
	if ( disk.numTracks()>0 )
	{
		soundTrack = disk.openTrack(track);
		soundChannel = soundTrack.play(0,int.MAX_VALUE);
		soundChannel.addEventListener(Event.SOUND_COMPLETE, cdda_loop_handler);
		cdda_current_track = track;
		cdda_playing = true;
	} 
	else
	{ 
		cdda_disabled = true;
	}
	return true;
}

private	function cdda_pause():void
{
	if	(cdda_disabled==true)
	{
		return;
	}

	if (soundChannel!=null)
	{
		soundPosition = soundChannel.position;
		soundChannel.removeEventListener(Event.SOUND_COMPLETE, cdda_loop_handler);
		soundChannel.stop();
		cdda_playing = false;
	}
}

private	function cdda_stop():void
{
	if (cdda_disabled==true)
	{
		return;
	}
	
	if (soundChannel!=null)
	{
		soundPosition = soundChannel.position;
		soundChannel.removeEventListener(Event.SOUND_COMPLETE, cdda_loop_handler);
		soundChannel.stop();
		cdda_playing = false;
	}
}

private	function cdda_resume():void
{
	if (cdda_disabled || cdda_playing)
	{
		return;
	}
	
	if (soundTrack!=null)
	{
		soundChannel = soundTrack.play(soundPosition,int.MAX_VALUE);
		soundChannel.addEventListener(Event.SOUND_COMPLETE, cdda_loop_handler);
		cdda_playing = true;
	}
}

private	function cdda_shutdown():void
{
	if (cdda_disabled==true)
	{
		return;
	}

	if (soundChannel!=null)
	{
		soundPosition = soundChannel.position;
		soundChannel.removeEventListener(Event.SOUND_COMPLETE, cdda_loop_handler);
		soundChannel.stop();
	}
}

private	function cdda_loop_handler(event:Event):void
{
	if (cdda_disabled==true)
	{
		return;
	}
	
	if (cdda_playing==true)
	{
		if (cdda_autoloop!=true)
		{
			cdda_stop();
		}
	}
}
