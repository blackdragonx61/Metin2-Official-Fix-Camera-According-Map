#Add
if app.__BL_FIX_CAMERA_ACCORDING_MAP__:
	FIX_CAMERA_INFO_BY_MAP = {
		"metin2_map_moonlight_boss": [ 1600.0, -1.0, 180.0, 136.0 ],
		"metin2_map_secretdungeon_01": [ 0.0, 13.0, -2.0, 130.0 ],
	}

#Find
		app.SetCamera(cameraDistance, cameraPitch, cameraRotation, cameraHeight)

#Change
		if app.__BL_FIX_CAMERA_ACCORDING_MAP__:
			self.FixCameraAccordingToMap()
		else:
			app.SetCamera(cameraDistance, cameraPitch, cameraRotation, cameraHeight)

#Add new func
	if app.__BL_FIX_CAMERA_ACCORDING_MAP__:
		def FixCameraAccordingToMap(self):
			mapName = background.GetCurrentMapName()

			if mapName in FIX_CAMERA_INFO_BY_MAP:
				c_dist, c_pitch, c_rot, c_height = FIX_CAMERA_INFO_BY_MAP[mapName]
				if c_dist == 0.0:
					c_dist = cameraDistance
				app.SetCamera(c_dist, c_pitch, c_rot, c_height)
			else:
				app.SetCamera(cameraDistance, cameraPitch, cameraRotation, cameraHeight)