class TraderAvailble
{
	static int CheckDayofWeek()
	{
		int year
		int month
		int day
		GetYearMonthDay(  year,  month,  day);
		Print("Maiar_TraderDays");
		int hour
		int minute
		int second
		//GetHourMinuteSecond(hour, minute, second)
		//Print(hour); Print(minute); Print(second);
		
		if (month == 1) {
			month = 13;
			year--;
		}
		if (month == 2) {
			month = 14;
			year--;
		}
		int q = day;
		int m = month;
		int k = year % 100;
		int j = year / 100;
		int h = q + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j; 
		
		h = h % 7;
		
		switch (h) 
		{
		case 0:
			Print( "Saturday ");
			break;
		case 1:
			Print( "Sunday ");
			break;
		case 2:
			Print( "Monday ");
			break;
		case 3:
			Print( "Tuesday ");
			break;
		case 4:
			Print( "Wednesday ");
			break;
		case 5:
			Print( "Thursday ");
			break;
		case 6:
			Print( "Friday ");
			break;
		}
		
		return h;
	};
	
	static int IsTraderAvailble()
	{
		
		int h = CheckDayofWeek();
		
		int g_Saturday = TraderDaysGlobals.Get().g_Saturday
		int g_Sunday = TraderDaysGlobals.Get().g_Sunday
		int g_Monday = TraderDaysGlobals.Get().g_Monday
		int g_Tuesday = TraderDaysGlobals.Get().g_Tuesday
		int g_Wednesday = TraderDaysGlobals.Get().g_Wednesday
		int g_Thursday = TraderDaysGlobals.Get().g_Thursday
		int g_Friday = TraderDaysGlobals.Get().g_Friday
		
		if( h == 0)
		{
			return g_Saturday;
		}
		if( h == 1)
		{
			return g_Sunday;
		}
		if( h == 2)
		{
			return g_Monday;
			
		}
		if( h == 3)
		{
			return g_Tuesday;
		}
		if( h == 4)
		{
			return g_Wednesday;
		}
		if( h == 5)
		{
			return g_Thursday;
		}
		if( h == 6)
		{
			return g_Friday;
		}
		return 0;
		Print("TraderChecked");
	}
	
}