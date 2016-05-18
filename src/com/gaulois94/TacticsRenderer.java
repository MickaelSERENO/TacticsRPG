package com.gaulois94;

import com.gaulois94.Graphics.Renderer;
import android.view.Surface;
import android.content.Context;
import android.util.Log;

public class TacticsRenderer extends Renderer
{
	public TacticsRenderer(Context c)
	{
		super(c);
	}

	@Override
	public long createPtr(long parent)
	{
		return createTacticsRenderer(parent);
	}

	static private native long createTacticsRenderer(long parent);
}
