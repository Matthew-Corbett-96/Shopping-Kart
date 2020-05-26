# Shopping-Kart
__Amazon Like Shopping Kart Console Application__ _-By Matthew J. Corbett_

## Todo's
- [ ] Way to know which system is being used to adjust the _clear_ command --> ` #if and #else ` ?? 
- [ ] Create a container for the Users to be stored in --> thinking an unordered multimap
- [ ] Change the UX of the looping system, more like a game loop. 
- [ ] Created a precompiled Header for all my libs being included.
- [ ] Figure Out how to change the color of the screen in the console --> `#include <windows.h>` needed 
- [ ] Sounds Files??? 
- [ ] Logging Class --> Lator 


## Logging Macro's 
// Figure this out later // 

## Game Loop Draft 1   
_Last Updated 5/26/2020_

`start_screen(); // get user info and create profile & push to the container of users`

 `main_game_loop()
  {
   bool shopping(true); //var to keep track if we avtivly using the application `

   `while(shopping)
   {
	std::unique_ptr<V_User> user // pointer to a user in the map of user`
	
	`choose_user(user, shopping) // choose which user you want to user or choose to exit
	
	while (active_session)
	{
		unsigned int op(0); // var for chosing an operation 
		choose_operation(int op); // decide which operation to do and return the number 

		switch (op)
			case 1: 
				clear_screen();
				add_items(V_User user);
				break;
			case 2:
				clear_screen();
				remove_items(V_user user);
				break;
			case 3:
				clear_screen();
				get_info(V_user user);
				break;
			case 4:
				clear_screen();
				edit_item(V_User user);
				break;
			case 5:
				clear_screen();
				print_kart(V_user user);
				break;
			case 6:
				clear_screen();
				print_history(V_user user);
				break;
			case 7:
				clear_screen();
				check_out(V_user user); 
				active = false;
				break;
			case 8:
				clear_screen();
				active = false; // sends user out of loop to picking a user loop; 
				break; 
			default: 
				clear_screen();
				// print invalid number 
				break;
				
				
	}

   }

   `good_bye(); //prints goodbye message to the user and sleeps for 5 seconds;
  
   return; 
  
 } // end of main game loop`




