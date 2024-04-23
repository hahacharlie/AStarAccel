// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vnodes_cache__pch.h"
#include "Vnodes_cache.h"
#include "Vnodes_cache___024root.h"
#include "Vnodes_cache___024unit.h"

// FUNCTIONS
Vnodes_cache__Syms::~Vnodes_cache__Syms()
{
}

Vnodes_cache__Syms::Vnodes_cache__Syms(VerilatedContext* contextp, const char* namep, Vnodes_cache* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(3471);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
