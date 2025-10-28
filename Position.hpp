#pragma once

struct Position {
    double x = 0;
    double y = 0;
    
    void move(double dx, double dy);    // Flytta punkten
    void print() const;                 // Skriv ut positionen
};