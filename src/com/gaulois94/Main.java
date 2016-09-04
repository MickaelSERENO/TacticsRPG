package com.gaulois94;

import com.gaulois94.TacticsRenderer;
import com.gaulois94.FileManager;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.widget.FrameLayout;

import android.util.Log;
import android.view.Window;
import android.graphics.Point;
import com.gaulois94.R;

public class Main extends Activity
{
	private TacticsRenderer m_renderer;

	public Main()
	{
	}

	public void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);
//		if(!Tool.isFileInData(this, "game.db"))
//		{
			FileManager.copyOnDevice(this);
//		}
		requestWindowFeature(Window.FEATURE_NO_TITLE);
		FileManager.initDB(this);
		m_renderer = new TacticsRenderer(this);
		setContentView(m_renderer.getSurface());
	}

	public void onResume()
	{
		super.onResume();
		setContentView(m_renderer.getSurface());
		m_renderer.resume();
	}

	public void onPause()
	{
		super.onPause();
		m_renderer.pause();
	}

	public void onDestroy()
	{
		super.onDestroy();
		m_renderer.destroy();
	}

	static
	{
		System.loadLibrary("expat");
		System.loadLibrary("engine");
		System.loadLibrary("tactics");
	}
}
