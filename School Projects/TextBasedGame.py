#Dennis Ray Ward II
def main():
    rooms = {#dictionary
            'Earth: Present Day': {'north': 'Morag','east': 'Kamar-Taj'},
            'Kamar-Taj': {'west': 'Earth: Present Day','Item':'Time Stone'},
            'Vormir': {'west': 'Morag','north': 'Wakanda','Item':'Soul Stone'},
            'Morag': {'west': 'New Jersey: 1970','east': 'Vormir','north': 'New York: 2012','south': 'Earth: Present Day','Item':'Power Stone'},
            'Wakanda': {'south': 'Vormir','Villain':'Thanos'},
            'New Jersey: 1970': {'east': 'Morag','Item':'Space Stone'},
            'New York: 2012': {'south': 'Morag','east': 'Asgard','Item':'Mind Stone'},
            'Asgard': {'west': 'New York: 2012','Item':'Reality Stone'}
        }

    inventory = []#initialize backpack
    global state
    state = 'Earth: Present Day'#sets first room

    def instrucitons():  # defines function inctructions
        print('Find all the infinity stone and kill Thanos.')
        print('Acceptable inputs are North, East, West, South, Search, Inventory, Instructions, and exit. capitalization does not matter.')
        print('The cardinal directions are for moving from room to room.')
        print('Search allows you to search the room for an item.')
        print('Inventory allows you to check your current inventory!')
        print('Instructions lets you recall these instructions!')
        print('If you wish to quit playing type exit')

    def moveroom(inp):
        global state#allows for modifying of our state
        state = rooms[state][inp]#sets new current room
        print('Current Room:', state)  # Prints info for user
        print('Inventory:',inventory)
        if 'Villain' in rooms[state]:#what if villain is in room?
            villainencounter()

    def pickup(current_room):#pickup an item
        if 'Item' in rooms[current_room] and rooms[current_room]['Item'] not in inventory:  # checks if item is in room and if it is already in inventory
            inventory.append(rooms[current_room]['Item'])
            print('You found the ' + rooms[current_room]['Item'] + ' it has been added to your inventory.')
        else:
                print('Nothing in this room'+current_room)

    def villainencounter():#villain encounter function
        global state
        if len(inventory) == 6:
            print('Congratulations you beat Thanos!')
            state = 'exit'
            print('You have beat the game! The game will now exit!')
        if len(inventory) != 6:
            print('You walk in and see Thanos, you dont have all the stones. Oh no!')
            state = 'Earth: Present Day'
            # inventory = []
            print('You do all you can but in the end you needed all 6 stones!')
            print('Current Room:', state)  # Prints current position


    instrucitons()#calls instructions
    print('Lets play!')
    print('Current Room:', state)  # Prints info for user
    print('Inventory:',inventory)
    while state != 'exit':#infite unless we exit
        print('-------------------------------------------------------------------------------')
        inp = input('You may enter a move or search the room!').lower()
        if inp in rooms[state]:# if input is in current room move room
            moveroom(inp)
        elif inp == 'search':#allows for picking up of item
            pickup(state)
        elif inp == 'inventory':#on demand inventory
            print(inventory)
        elif inp == 'exit':#if exit is entered, for apropriate output can not continue game
            state = 'exit'
        elif inp == 'set':#for internal testing
            inp = input('stones')
            inventory = inp.split(',')
            inp = input('current room')
            state = inp
            if inp == 'win':
                inventory = [1,1,1,1,1,1]
                state ='Vormir'
        elif inp == 'instructions':#to share instuctions again
            instrucitons()
        else:#incase input is not correct
            print('Sorry that was not an acceptable input! Type "Instructions" for acceptable inputs')

    print('You are no longer playing! Restart the game if you wish to play again.')
    input()#keeps command prompt open
main()