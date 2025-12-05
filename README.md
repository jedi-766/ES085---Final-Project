
# Educational Purpose Only (ES085 - Computer Programming 2 - Final Project)
---

# Physics Calculator (C Language)

A modular, menu-driven physics calculator written in C.  
This program performs essential physics computations from introductory mechanics, including kinematics, forces, work & energy, momentum, and universal gravitation.

---

## 📌 Features

### **Kinematics**
- Computes final velocity using `v = u + at`.  
- Computes displacement using `s = ut + ½at²`.  
- Validates time input to prevent non-physical values.

### **Forces**
- Calculates force using Newton’s 2nd Law `F = ma`.  
- Computes weight using `W = mg`.  
- Rejects negative mass values.

### **Work & Energy**
- Calculates work using `W = Fd`.  
- Computes kinetic energy using `KE = ½mv²`.  
- Ensures mass and velocity are valid.

### **Momentum & Collisions**
- Calculates momentum using `p = mv`.  
- Simulates an elastic collision of equal-mass objects (velocity swap).  
- Uses pointers to return multiple results.

### **Universal Gravitation**
- Calculates centripetal force using `Fc = mv² / r`.  
- Calculates centripetal acceleration using `ac = v² / r`.  
- Validates radius for physically meaningful input.

---


## 📂 Program Structure

The program uses a clean, modular architecture:

```
Main Menu Loop
   ├── Kinematics Module
   ├── Forces Module
   ├── Work & Energy Module
   ├── Momentum Module
   └── Universal Gravitation Module
```

Each module contains its own input handling and calls dedicated formula functions.

## 🧠 Programming Concepts Demonstrated

- Modular functions for each physics formula
- Procedural programming structure
- Input validation
- Switch–case menu system
- Pointer use for returning multiple values
- Clear separation of logic and computation

