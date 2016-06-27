package com.gaulois94;

import com.gaulois94.Tool;
import android.content.Context;

public class FileManager
{
	public static GAMEDB = "game.db"
	static void copyOnDevice(Context c)
	{
		Tool.copyAssetToData(c, GAMEDB);
	}

	static void initDB(Context c)
	{
		initDB(c.getFilesDir() + "/" + GAMEDB);
	}

	static native void FileManagerInitDB(String pathDB);
}
