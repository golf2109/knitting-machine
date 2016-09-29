How to setup the button debounce module

Steps
1) Include the header and source file in your project
2) Define a gpio_config.h module with masks to access gpio pins
3) Define a gpio module containing a Dio_ChannelRead function

* Steps 2 and 3 could be substituted for a quick and dirty gpio driver

4) Define which I/O pins are buttons in ButtonList[] in button.c
5) Set the default state for each button in ButtonCurrentState
6) Set the debounce count for each button in ButtonDebounceCountList.
   For example, if Button_Debounce is called in the 10ms task and the
   debounce is 40 ms then the count would be 4.
7) In button.h, update Button_t enum for the buttons present.  If only
   one button then there should be one button defined in the enum.
8) Call Button_Init in the system initialization
9) Call Button_Debounce in the desired task.  10 millisecond task is 
   recommended.
10) Write an application to use the button module.  An example application
    that could be placed in a 10 ms task is below:


Example application:
	Button_State_t Button1State = BUTTON_STATE_NOT_PRESSED;

	// Debounce the switch(es)
	Button_Debounce();

	Button1State = Button_StateGet(BUTTON_PRIMARY);

	if(Button1State == BUTTON_STATE_PRESSED)
	{
		Led_On(LED_RED);
	}
	else
	{
		Led_Off(LED_RED);
	}
