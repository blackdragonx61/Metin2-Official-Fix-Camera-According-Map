//Find
PyObject* appSetCameraMaxDistance(PyObject* poSelf, PyObject* poArgs)
{
	...
}

///Change
PyObject* appSetCameraMaxDistance(PyObject* poSelf, PyObject* poArgs)
{
	float fMax = 0.0f;
	
	static const std::map<std::string, std::pair<float, float>> CameraDistanceMap = {
		{ "metin2_map_n_flame_dragon", std::make_pair(6000.0f, 6000.0f) },
		{ "metin2_12zi_stage", std::make_pair(5000.0f, 5000.0f) },
		{ "metin2_map_defensewave", std::make_pair(5000.0f, 5000.0f) },
		{ "metin2_map_miniboss_01", std::make_pair(5000.0f, 5000.0f) },
		{ "metin2_map_miniboss_02", std::make_pair(5000.0f, 5000.0f) },
		{ "metin2_map_mists_of_island", std::make_pair(5000.0f, 5000.0f) },
		{ "metin2_map_guild_whitedragon_boss", std::make_pair(7000.0f, 7000.0f) },
		{ "metin2_map_moonlight_boss", std::make_pair(2500.0f, 5500.0f) },
		{ "metin2_map_greedy_room", std::make_pair(7000.0f, 7000.0f) },
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
		const std::pair<float, float>& distance = it->second;
		fMax = CPythonSystem::Instance().GetCameraMode() ? distance.second : distance.first;
	}

	CCamera::SetCameraMaxDistance(fMax);
	return Py_BuildNone();
}