# 4-Slot Geneva Drive 

A mechanical engineering project where I designed, calculated, 3D printed, and tested a four-slot Geneva drive.

The main version of the mechanism is hand-spun. I also modified the CAD files for a NEMA 17 stepper motor, but I have not yet built and tested the motorized version, however, I'm positive it will transition smoothly.

## What is a Geneva Drive?

A Geneva drive converts continuous rotation into intermittent motion. The driver rotates continuously, while the Geneva wheel moves one position at a time and then locks in place. 

I chose to build one because it is a fairly simple mechanism to understand, but even the smallest mathematical  or clearance error can make a big difference once the parts are printed and assembled/

#Design

I designed the mechanism in Fusion 360 and printed the parts in PETG on a Bambu Lab P1S.

The design uses four slots, so the Geneva wheel rotates 90° each time it is turned.

| Parameter | Value |
|---|---|
| Slots (n) | 4 |
| Driven wheel radius (b) | 50.00 mm |
| Drive crank radius (a) | 50.00 mm |
| Center distance (C) | 70.71 mm |
| Pin diameter | 6.00 mm |
| Slot width | 6.35 mm |
| Design clearance (PETG) | 0.35 mm |
| Plate thickness | 8.00 mm |
| Locking wall diameter (as-tuned) | 80.50 mm |

The calculations and dimensions are included in the spreadsheet in this repository.

## Working Through the Geometry

My first set of dimensions had failed.

The crank radius and the Geneva wheel geometry did not allow the pin to reach the slots correctly. After going back through the geometry, I found that the four slot design required the crank radius to match the driven wheel radius.

I rebuilt the dimensions using the geometry of a four-slot Geneva mechanism and then checked the results against a published Geneva wheel design from FreeCAD.

This was a much better starting point for me.

## The Locking Mechanism

The locking mechanism was the part that was the most tedious.

My first design used a recessed area on the driver wheel to lock the Geneva wheel between rotations. It looked correct at one position, but once I printed it and turned the mechanism, the two parts interfered with each other at the points of rotation.

From what I understood, the problem was that I shaped the locking surface around the wrong center.

I went back to the standard geometry used in Geneva mechanisms and redisgned the 

I went back to the standard geometry used in Geneva mechanisms and redesigned the driver with a raised locking section and an opening for the Geneva wheel to pass through.

I also calculated the opening using the intersection of two circles instead of estimating the shape by eye.

The new print worked much better. There was still some grinding during the locking portion of the motion, so I traced the problem to the clearance around the locking wall. I reduced its diameter by 0.5 mm and printed it again.

After that adjustment, the mechanism moved smoothly by hand.

##Physical Testing

The final mechanical version was tested by hand.

I checked that:

The Geneva wheel moves through all four positions.
The wheel locks between each position.
The pin enters and leaves the slots without getting stuck.
The mechanism can complete repeated rotations.
The printed parts have enough clearance to move without excessive friction.

The final version successfully completes the four-position indexing cycle by hand.

##NEMA 17 Version

I also created a modified version of the CAD design for a NEMA 17 stepper motor.

The repository includes:

Modified Fusion 360 assemblies
STEP files
STL files
A preliminary Arduino .ino file

The motorized version is not currently completed or physically tested. The main mechanism in this project is still the hand-spun version.

I included the motor-compatible files because I want to eventually automate the mechanism and test how well the printed Geneva drive performs under continuous motor-driven rotation.

Files
File	Description
GenevaCADfile.f3z	Original Fusion 360 assembly
GenevaCADfiles.step	STEP version of the Geneva drive
GenevaCADfiles.stl	STL files for 3D printing
Geneva_Drive_Calculator_1.xlsx	Design calculations and dimensions
Geneva_Sideview.png	Side view of the design
Geneva_Topview.png	Top view of the design
Nema - 17 - Geneva Drive'.stl	Modified STL for NEMA 17 integration
Nema 17 - Geneva Drive.step	Modified STEP model
Nema 17 - Geneva Drive.f3z	Modified Fusion 360 assembly
nema17_geneva_driver.ino	Preliminary Arduino motor-control code
LICENSE	Project license
Tools and Materials
Fusion 360
Bambu Lab P1S
PETG
3D printing
Excel
Arduino files for future motor integration
FreeCAD for checking the Geneva mechanism geometry
What I Learned

This project taught me that getting the math right is only part of designing a mechanical system.

My first design looked reasonable on paper, but the printed parts showed problems that were not obvious from the original model. I had to go back to the geometry, figure out why the parts were interfering, change the design, print it again, and test it.

The locking mechanism was especially useful because the first version technically looked like it should work, but physical testing showed that it didn't.

That process of designing, printing, testing, finding a problem, and changing the design is what I wanted to document with this project.

Future Plans

The next step is to finish the NEMA 17 version and test the Geneva drive under motor power.

I would also like to experiment with different print clearances and materials to see how they affect friction, movement, and the locking mechanism.

License

This project is open source. See the LICENSE file for the license terms.
