Timer-Based LED Control

1] Introduction to Timer Peripheral
1. Timer is a hardware module which takes inputs from the clock and measures the time. It can be coded as per requirement unlike the clock.
2. Hardware timers measure time independently, not disturbing the CPU, thus allowing the CPU to carry out other tasks. Whereas software delays, measure time by running the loop of instructions for a specific amount of time, thus blocking the CPU to do other code execution, reducing efficiency. Also, hardware timers offer high precision unlike the software delays which might get affected due to internal interruptions.
3. The timer has 3 key components, which are 'prescalar', 'counter' and 'auto-reload'. The timer takes clock signal as the input, but the clock signal can be very high, for example; 16MHz, which is more than whats required. The prescalar helps scale down this clock signal like follows; if we set the prescalar value as 15999, then only one pulse will be sent after 16000 cycles (15999+1). So the new frequency will become 1000Hz, which is much better to play with. Now the counter counts (/increments) 1 after getting a pulse from the prescalar. Finally, the auto-reload resets the counter back to 0, and whenever this reset happens, an 'event' is triggered signifying that whatever time we had set is up. For a delay of 2 seconds, we can set the value of auto-reload as 1999, so after 2000 counts (1999+1), the counter resets, telling us that 2 seconds have passed by.

2] Register Configuration
1.
