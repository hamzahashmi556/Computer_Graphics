#include <iostream>
#include <fstream>
#include <string>
//using namespace std;

#include<windows.h> 
#include"mmsystem.h"
int main()
{
	PlaySound(TEXT("Battlepack_TankSkin-e5669d14.wav"),NULL,SND_SYNC);
	/*TEXT("Rains Of Castamere Instrumental.wav"): This is the first argument to the PlaySound function and specifies the name of the audio file to be played. The TEXT macro is used to make the string compatible with both Unicode and ANSI character encodings, depending on the build configuration of the program.
    NULL: This is the second argument, and it represents a handle to a module (in this case, NULL indicates the current module). It's not used in this context and can be set to NULL.
   SND_SYNC: This is the third argument and is a flag that specifies how the sound should be played. SND_SYNC indicates that the sound should be played synchronously, which means the PlaySound function will not return until the sound has finished playing.
    */
	return 0;
}
