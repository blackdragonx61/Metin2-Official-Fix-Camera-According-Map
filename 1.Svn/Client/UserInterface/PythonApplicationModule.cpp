//Find
PyObject* appSetCameraMaxDistance(PyObject* poSelf, PyObject* poArgs)
{
	...
}

///Change
PyObject* appSetCameraMaxDistance(PyObject* poSelf, PyObject* poArgs)
{
	float fMax;
	if (!PyTuple_GetFloat(poArgs, 0, &fMax))
		return Py_BuildException();

	const std::string c_rstrMapFileName = CPythonBackground::Instance().GetWarpMapName();

	if (!c_rstrMapFileName.compare("metin2_map_n_flame_dragon"))
		fMax = 6000.0f;
	else if (!c_rstrMapFileName.compare("metin2_12zi_stage"))
		fMax = 5000.0f;
	else if (!c_rstrMapFileName.compare("metin2_map_defensewave"))
		fMax = 5000.0f;
	else if (!c_rstrMapFileName.compare("metin2_map_miniboss_01"))
		fMax = 5000.0f;
	else if (!c_rstrMapFileName.compare("metin2_map_miniboss_02"))
		fMax = 5000.0f;
	else if (!c_rstrMapFileName.compare("metin2_map_mists_of_island"))
		fMax = 5000.0f;
	else if (!c_rstrMapFileName.compare("metin2_map_guild_whitedragon_boss"))
		fMax = 7000.0f;
	else if (!c_rstrMapFileName.compare("metin2_map_moonlight_boss"))
		fMax = 5500.0f;
	else if (!c_rstrMapFileName.compare("metin2_map_greedy_room"))
		fMax = 7000.0f;

	CCamera::SetCameraMaxDistance(fMax);
	return Py_BuildNone();
}