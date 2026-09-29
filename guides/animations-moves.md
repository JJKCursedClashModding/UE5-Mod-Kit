# Animations & Move Tweaking

Find the move you want (it will be named AM_CP_NNN_MOVE_ID) and right click -> Recreate Montage(s)

<img width="3840" height="2160" alt="image" src="https://github.com/user-attachments/assets/8b76ca1c-6dfe-41a8-bdee-e7082d7b5094" />

Once done, you can double click the file to open the animation montage editor. Make sure to click 'Disable' on the "Post process animation blueprint ...." warning (otherwise the animation will be stuck in default pose)

<img width="3840" height="2160" alt="image" src="https://github.com/user-attachments/assets/b9b4be63-0106-445e-89ac-90c497d37d8f" />

Now you can edit all move properties that are not editable by data table, such as: animation speed, change damage record id, add cancel windows, sound or graphic effects, etc

As an example, I'll show you how to edit the damage record id:

To start, select the 'Game Anim NS Attack Collision' under 'Notifies':

<img width="3840" height="2160" alt="image" src="https://github.com/user-attachments/assets/a008c9d4-e915-454e-9685-45f4ed6005f8" />

Then, you can edit 'Group Name' to change the damage record id:

<img width="3840" height="2160" alt="image" src="https://github.com/user-attachments/assets/2a7fc4e1-5500-467d-902f-fbf2116df0dd" />

Why is this useful? Two reasons:
1. You can copy the animation and make a completely new move that does it's own damage. It's not tied to the original move damage any more
2. You can add damage notifies to make a move multi-hit

How do you add a new notify track?

<img width="3840" height="2160" alt="image" src="https://github.com/user-attachments/assets/bd796a82-8fa3-4c15-aab1-1dbdfc3b40c9" />



I don't remember what this picture was for, but there's probably a reason I took it.

<img width="3840" height="2160" alt="image" src="https://github.com/user-attachments/assets/16c1c450-3bb5-4d8a-bace-d32992caeea3" />







