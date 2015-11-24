# Arduino-Traffic-Light-system
Pedestrian crossing traffic light system : </br>
Your task is to use an Arduino, LEDs, resistors and buttons to build a simple Traffic light system on a Breadboard,
and to program its logic.

![alt tag](http://osoyoo.com/wp-content/uploads/2014/12/ped_traffic_light.jpg)

Here is what needs to be simulated: one main road, one pedestrian crossing. The Pedestrian crossing has a button.
The main road’s traffic light is green by default and the pedestrian light is red. When the button is pressed, the main
traffic light goes red. Then, the pedestrian traffic light will go green.
After this the pedestrian light goes red again, and in the end the main traffic light goes green again.
Between each of these changes is a delay, and the traffic light for the main road also has yellow phases in the
sequence. Example (red – yellow – green – yellow – red or red – red+yellow – green – yellow – red, or what else might be the case).

(<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>) 
Use the following techniques to implement the System in a neat and easy to read way:
- Use a timer rather than a delay() between each change.
- Use a Finite State Machine (or more if you like) to implement the system.
Note: unfortunately the simulator does not allow you to import external libraries such as timer.h. Please implement a
function called update_timer(), which uses a single delay() and updates a global variable (int timer) and whatever else
you think you need. Then check and reset this global variable as you need in the rest of your program. There
shouldn’t be a single other delay() in your program. As you can imagine, this function should be called regularly in
your loop().
