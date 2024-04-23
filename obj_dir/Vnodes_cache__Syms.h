// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VNODES_CACHE__SYMS_H_
#define VERILATED_VNODES_CACHE__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vnodes_cache.h"

// INCLUDE MODULE CLASSES
#include "Vnodes_cache___024root.h"
#include "Vnodes_cache___024unit.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vnodes_cache__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vnodes_cache* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vnodes_cache___024root         TOP;

    // CONSTRUCTORS
    Vnodes_cache__Syms(VerilatedContext* contextp, const char* namep, Vnodes_cache* modelp);
    ~Vnodes_cache__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
