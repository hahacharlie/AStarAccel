// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vnodes_cache.h for the primary calling header

#ifndef VERILATED_VNODES_CACHE___024UNIT_H_
#define VERILATED_VNODES_CACHE___024UNIT_H_  // guard

#include "verilated.h"


class Vnodes_cache__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vnodes_cache___024unit final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vnodes_cache__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vnodes_cache___024unit(Vnodes_cache__Syms* symsp, const char* v__name);
    ~Vnodes_cache___024unit();
    VL_UNCOPYABLE(Vnodes_cache___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
