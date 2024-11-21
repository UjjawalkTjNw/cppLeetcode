int logThrottle::checkForThrottling(const std::string fileName = "$" , const int lineNo = 0)
{

	std::string log_key = fileName + ":" + intToString(lineNo);
	time_t logTime = time(0);
	time_t failTime = (time_t)(-1);
	if (firstIntervalTime == failTime)
	{
		firstIntervalTime = logTime;
	}
	double diff_time = difftime(logTime, firstIntervalTime);
	if (diff_time < throttleInterval)
	{
		if(logCount.count(log_key)==0)
		{
			logCount[log_key] = 1;
		}
		else
		{
			logCount[log_key]++;
			if (logCount[log_key] >= maxOccurrences)
			{
				return logCount[log_key];
			}
		}
	}
	else
	{
		int count = logCount[log_key];
		logCount.clear();
		firstIntervalTime = logTime;
		return count;
	}

	return logCount[log_key];
}




bool checkLogParams(const char* fileStr, int lineNo, char* prefixStr)
{
    int len = 0;
    memset(prefixStr, 0, 128);
#if (defined(INCLUDE_FILE_LINE_IN_LOG) || defined(INCLUDE_FILE_IN_LOG))
    len += sprintf(prefixStr+len, "%s:", fileStr);
#else
    fileStr = "$";
#endif
#if (defined(INCLUDE_FILE_LINE_IN_LOG) || defined(INCLUDE_LINE_IN_LOG))
    len += sprintf(prefixStr+len, "%d:", lineNo);
#else
    lineNo = 0;
#endif
    bool printLog = len ? false : true;
    if (LOG_THROTTLING_ENABLED && logThrottlePtr) {
        int currentLogCount = logThrottlePtr->checkForThrottling(fileStr, lineNo);
        if (currentLogCount <= logThrottlePtr->getMaxOccurrences()) {
            printLog = true;
        } else if (currentLogCount > logThrottlePtr->getMaxOccurrences()) {
            time_t currentTimestamp = ::time(0);
            if (currentTimestamp - lastPrintTime >= 60) {
                Log->logBegin();
                (Log->File()) << "==================== LOG THROTTLING SUMMARY START ====================\n\n";
                (Log->File()) << prefixStr << " Occurred " << currentLogCount << " times\n";
                (Log->File()) << "==================== LOG THROTTLING SUMMARY END ======================\n\n";
                Log->logEnd();
                lastPrintTime = currentTimestamp;
            }
        }
    } else if (!LOG_THROTTLING_ENABLED) {
        printLog = true;
    }
    return printLog;
}
