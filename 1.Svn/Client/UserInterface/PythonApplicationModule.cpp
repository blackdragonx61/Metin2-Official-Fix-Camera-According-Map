//Find
PyObject* appSetCameraMaxDistance(PyObject* poSelf, PyObject* poArgs)
{
	...
}

///Change
#if defined(__BL_FIX_CAMERA_ACCORDING_MAP__) && defined(__BL_SAVE_CAMERA_MODE__)
PyObject* appSetCameraMaxDistance(PyObject* poSelf, PyObject* poArgs)
{
	float fMax = 0.0f;
	
	static const std::map<std::string, std::pair<float, float>> CameraDistanceMap = {
		{ "metin2_map_n_flame_dragon", { 6000.0f, 6000.0f } },
		{ "metin2_12zi_stage", { 5000.0f, 5000.0f } },
		{ "metin2_map_defensewave", { 5000.0f, 5000.0f } },
		{ "metin2_map_miniboss_01", { 5000.0f, 5000.0f } },
		{ "metin2_map_miniboss_02", { 5000.0f, 5000.0f } },
		{ "metin2_map_mists_of_island", { 5000.0f, 5000.0f } },
		{ "metin2_map_guild_whitedragon_boss", { 7000.0f, 7000.0f } },
		{ "metin2_map_moonlight_boss", { 2500.0f, 5500.0f } },
		{ "metin2_map_greedy_room", { 7000.0f, 7000.0f } },
		{ "metin2_map_n_flame_dragon_pass", { 6000.0f, 6000.0f } },
		{ "metin2_map_guild_whitedragon_boss_pass", { 7000.0f, 7000.0f } },
	};

	const std::string c_rstrMapFileName = CPythonBackground::Instance().GetWarpMapName();
	auto it = CameraDistanceMap.find(c_rstrMapFileName);
	if (it == CameraDistanceMap.end())
	{
		if (!PyTuple_GetFloat(poArgs, 0, &fMax))
			return Py_BuildException();
	}
	else
	{
		const auto& distance = it->second;
		fMax = CPythonSystem::Instance().GetCameraMode() ? distance.second : distance.first;
	}

	CCamera::SetCameraMaxDistance(fMax);
	return Py_BuildNone();
}
#else
PyObject* appSetCameraMaxDistance(PyObject* poSelf, PyObject* poArgs)
{
	float fMax;
	if (!PyTuple_GetFloat(poArgs, 0, &fMax))
		return Py_BuildException();

	CCamera::SetCameraMaxDistance(fMax);
	return Py_BuildNone();
}
#endif

///Add
#if defined(__BL_FIX_CAMERA_ACCORDING_MAP__)
	PyModule_AddIntConstant(poModule, "__BL_FIX_CAMERA_ACCORDING_MAP__", true);
#else
	PyModule_AddIntConstant(poModule, "__BL_FIX_CAMERA_ACCORDING_MAP__", false);
#endif