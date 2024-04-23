// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vnodes_cache.h for the primary calling header

#include "Vnodes_cache__pch.h"
#include "Vnodes_cache__Syms.h"
#include "Vnodes_cache___024root.h"

void Vnodes_cache___024root___ctor_var_reset(Vnodes_cache___024root* vlSelf);

Vnodes_cache___024root::Vnodes_cache___024root(Vnodes_cache__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vnodes_cache___024root___ctor_var_reset(this);
}

void Vnodes_cache___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vnodes_cache___024root::~Vnodes_cache___024root() {
}
