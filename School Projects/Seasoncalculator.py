input_month = input('Month?')
input_day = int(input('Day?'))
# large set of lists I plan to use in order to do less statements
months = ['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November',
          'December']
days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
springmonths = ['March', 'April', 'May', 'June']
springdays = [20, 31, 31, 20]
summermonths = ['June', 'July', 'August', 'September']
summerdays = [21, 31, 31, 21]
autumnmonths = ['September', 'October', 'November', 'December']
autumndays = [22, 31, 31, 20]
wintermonths = ['December', 'January', 'February', 'March']
winterdays = [21, 31, 31, 19]
if input_month in months:  # checks validity
    i = months.index(input_month)  # gets position of the correct number of maximum days for the month input
    if 1 <= input_day <= days[i]:  # checks day for validity for specific month
        if input_month in springmonths:  # beging to check if spring
            i = springmonths.index(input_month)  # checking position of month in list to get date range
            if i != 0 and 1 <= input_day <= springdays[i]: #checking day
                output = 'Spring' #setting output
            elif i == 0 and springdays[i] <= input_day < 31: #checking max doesnt really matter as its already been checked if valid
                output = 'Spring' #setting output

        if input_month in summermonths:  # beging to check if summer
            i = summermonths.index(input_month)  # checking position of month in list to get date range
            if i != 0 and 1 <= input_day <= summerdays[i]: #checking day
                output = 'Summer'#setting output
            elif i == 0 and summerdays[i] <= input_day < 31: #checking day
                output = 'Summer'#setting output

        if input_month in autumnmonths:  # beging to check if summer
            i = autumnmonths.index(input_month)  # checking position of month in list to get date range
            if i != 0 and 1 <= input_day <= autumndays[i]: #checking day
                output = 'Autumn'#setting output
            elif i == 0 and autumndays[i] <= input_day < 31: #checking day
                output = 'Autumn'#setting output

        if input_month in wintermonths:  # beging to check if summer
            i = wintermonths.index(input_month)  # checking position of month in list to get date range
            if i != 0 and 1 <= input_day <= winterdays[i]: #checking day
                output = 'Winter'#setting output
            elif i == 0 and winterdays[i] <= input_day < 31: #checking day
                output = 'Winter'#setting output
   
    else:
        output = 'Invalid'
else:
    output = 'Invalid'
print(output)
        #this could also be done with less lines with a loop as well but im not completely familiar with python yet
        #I also probably over thought it a little bit.
input()