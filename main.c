/*
 * 🚨 WARNING: CHALLENGE MODE ACTIVATED 🚨
 * 
 * 1️⃣ Sit back, take a deep breath, and **THINK**.
 * 2️⃣ For the next **10 minutes**, avoid using **Gen AI, ChatGPT, or any shortcuts**.
 * 3️⃣ Trust your **brain**—you’re smarter than you think!
 * 4️⃣ Consider yourself a **LOSER** if you cheat. Seriously, promise yourself you won't. 😤
 * 5️⃣ If you solve it on your own, **you WIN** and level up as a true programmer and come and meet me ! 
 * 
 * 
 * 💡 Remember: The best coders aren’t the ones who copy-paste. They are the ones who **struggle, think, fail, and then succeed.** 
 *    
 * Now, write your code! You got this! 💪🔥
 */

 #include <stdio.h>

 // Function declarations
 void initializeSystem(int rooms, int lights[], int temps[], int motion[], int locks[]);
 void toggleLight(int room, int lights[]);
 void readTemperature(int room, int temps[]);
 void checkMotionSensor(int room, int motion[]);
 void lockUnlockDoor(int room, int locks[]);
 void houseStatus(int rooms, int lights[], int temps[], int motion[], int locks[]);
 void autoLockSystem(int rooms, int motion[], int locks[], int *noMotionCount);
 
 int main() {
     int rooms, choice, room;
     int noMotionCount = 0;
     
     // Get the number of rooms
     printf("Enter number of rooms: ");
     scanf("%d", &rooms);
     
     // Arrays for home automation system
     int lights[rooms], temps[rooms], motion[rooms], locks[rooms];
     
     // Initialize system
     initializeSystem(rooms, lights, temps, motion, locks);
     
     while (1) {
         printf("\n===== Smart Home Menu =====\n");
         printf("1. Toggle Light\n2. Read Temperature\n3. Check Motion Sensor\n4. Lock/Unlock Security System\n5. House Status Summary\n6. Exit\n");
         printf("Enter your choice: ");
         scanf("%d", &choice);
         
         switch (choice) {
             case 1:
                 printf("Enter room number to toggle light (1-%d): ", rooms);
                 scanf("%d", &room);
                 toggleLight(room - 1, lights);
                 break;
             case 2:
                 printf("Enter room number to read temperature (1-%d): ", rooms);
                 scanf("%d", &room);
                 readTemperature(room - 1, temps);
                 break;
             case 3:
                 printf("Enter room number to check motion (1-%d): ", rooms);
                 scanf("%d", &room);
                 checkMotionSensor(room - 1, motion);
                 break;
             case 4:
                 printf("Enter room number to lock/unlock (1-%d): ", rooms);
                 scanf("%d", &room);
                 lockUnlockDoor(room - 1, locks);
                 break;
             case 5:
                 houseStatus(rooms, lights, temps, motion, locks);
                 break;
             case 6:
                 printf("Exiting...\n");
                 return 0;
             default:
                 printf("Invalid choice. Try again.\n");
         }
         
         // Auto-lock mechanism
         autoLockSystem(rooms, motion, locks, &noMotionCount);
     }
     return 0;
 }
 
 void initializeSystem(int rooms, int lights[], int temps[], int motion[], int locks[]) {
     for (int i = 0; i < rooms; i++) {
         lights[i] = 0;      // Lights OFF
         temps[i] = 22 + (i % 5);  // Random temperatures (22-26)
         motion[i] = 0;      // No motion detected
         locks[i] = 1;       // Doors locked
     }
     printf("System initialized.\n");
 }
 
 void toggleLight(int room, int lights[]) {
     lights[room] = !lights[room];
     printf("Light in Room %d is now %s.\n", room + 1, lights[room] ? "ON" : "OFF");
 }
 
 void readTemperature(int room, int temps[]) {
     printf("Temperature in Room %d: %d°C\n", room + 1, temps[room]);
     if (temps[room] > 30) {
         printf("Warning: High Temperature in Room %d!\n", room + 1);
     }
 }
 
 void checkMotionSensor(int room, int motion[]) {
     printf("Motion in Room %d: %s\n", room + 1, motion[room] ? "Detected" : "No Motion");
 }
 
 void lockUnlockDoor(int room, int locks[]) {
     locks[room] = !locks[room];
     printf("Room %d is now %s.\n", room + 1, locks[room] ? "Locked" : "Unlocked");
 }
 
 void houseStatus(int rooms, int lights[], int temps[], int motion[], int locks[]) {
     printf("\nHouse Status:\n");
     for (int i = 0; i < rooms; i++) {
         printf("- Room %d: Light %s, Temp %d°C, %s, %s\n", i + 1,
                lights[i] ? "ON" : "OFF",
                temps[i],
                motion[i] ? "Motion Detected" : "No Motion",
                locks[i] ? "Locked" : "Unlocked");
     }
 }
 
 void autoLockSystem(int rooms, int motion[], int locks[], int *noMotionCount) {
     int motionDetected = 0;
     for (int i = 0; i < rooms; i++) {
         if (motion[i] == 1) {
             motionDetected = 1;
             break;
         }
     }
     
     if (!motionDetected) {
         (*noMotionCount)++;
     } else {
         *noMotionCount = 0;
     }
     
     if (*noMotionCount >= 5) {
         for (int i = 0; i < rooms; i++) {
             locks[i] = 1;  // Auto-lock all doors
         }
         printf("Auto-Lock Activated: All rooms are now locked.\n");
         *noMotionCount = 0;
     }
 }
 