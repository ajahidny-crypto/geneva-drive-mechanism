# 4-Slot Geneva Drive — Parametric Design, 3D Print & Motor Control



A Geneva drive takes one simple, continuous spin and turns it into something far more precise, a series of exact locked steps, with nothing controlling any of it but the shape of the metal itself, no motor deciding when to move, no code deciding when to stop, just pure geometry doing all the work, till the pin lines up again and the whole thing repeats. It's the same mechanism that used to pull film through old movie projectors, one frame at a time, and I wanted to build a real, working version of it myself, from scratch, a 4-slot design, printed in PETG on a Bambu Lab P1S, and eventually driven by a NEMA 17 stepper motor.

## The Design Problem

The first set of numbers I started with looked complete, everything filled in, nothing obviously missing, but it turned out to be geometrically impossible, because for a 4-slot Geneva drive, getting the pin to enter the slot cleanly, without any shock or grinding, requires the crank radius to equal the driven wheel's radius exactly, a special case that comes straight out of the fact that sin(45°) and cos(45°) are the same number, and the original spec had that crank radius set to something else entirely, meaning the pin would never have actually reached the slot in the first place.

Once I caught that, I rebuilt the whole geometry from the actual trigonometric relationships underneath it, and then went further, cross-checking every dimension that came out of it, the center distance, the slot depth, the locking-disc sizing, against a real, published reference design (the FreeCAD "Geneva Wheel" macro), just to make sure the math lined up with how these things are actually built, not just with itself.

## The Harder Problem

The part that actually gave me trouble was the locking mechanism, the piece responsible for keeping the star wheel completely still between each step, and my first attempt at solving it seemed to work, I cut a pocket directly into the driver wheel's body, hand-fit it against the star wheel's edge at one specific angle, printed it, and it moved.

Then testing showed the real problem. That pocket only matched the star wheel's curve at the one angle I'd fit it to, since it was shaped around the star wheel's own center, not the driver's, and because the driver spins around a completely different axis, everywhere else in the rotation the two shapes fought each other instead of sliding smoothly, stabbing, dragging, and every so often throwing the pin off just enough to miss the next step entirely.

That sent me back to actually research how real Geneva mechanisms handle this, and it turns out the standard design isn't a recessed cut at all, it's the opposite, a raised, elevated locking disc, a stepped boss built up on the driver's own face, with a crescent-shaped opening cut out of it so the star wheel's corner has room to pass through during engagement. I rebuilt the driver wheel around that idea, and this time sized the opening using actual verified two-circle intersection geometry instead of eyeballing it like before.

The reprint came out close to perfect on the very first try, smooth indexing, just a small bit of grinding during the lock phase, and instead of reshaping the opening again, I traced it back to the wall itself, shaved its diameter down by half a millimeter, and that was it, the grinding was gone.

## Control System

The whole mechanism runs off a NEMA 17 stepper (17HS19-2004S1), controlled through an Arduino and a standard STEP/DIR driver board (A4988/DRV8825), spinning continuously, since the Geneva geometry itself handles all the actual indexing, the motor just needs to keep turning smoothly and nothing more. Full wiring notes and current-limit setup are documented right in the code.

The whole project, CAD files, motor control code, and every bit of build documentation, is published open-source on GitHub.

## Specs

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
| Driver motor | NEMA 17 (17HS19-2004S1) |

## Outcome

It indexes cleanly through all four positions under motor power, the locking wall holds the star wheel completely still between steps, and there's no drift, no missed indexing, nothing. Full source, the CAD, the formulas, the firmware, all of it, is up on GitHub.

## Tools

Fusion 360 · Bambu Lab P1S · PETG · Arduino · FreeCAD (verification) · GitHub

---

*Every derivation, every formula source, and the full interactive calculator are sitting in the accompanying spreadsheet, if you want to go deeper.*
