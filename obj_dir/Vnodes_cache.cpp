// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vnodes_cache__pch.h"

//============================================================
// Constructors

Vnodes_cache::Vnodes_cache(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vnodes_cache__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , valid{vlSymsp->TOP.valid}
    , write{vlSymsp->TOP.write}
    , hit{vlSymsp->TOP.hit}
    , address{vlSymsp->TOP.address}
    , data_in{vlSymsp->TOP.data_in}
    , data_out{vlSymsp->TOP.data_out}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vnodes_cache::Vnodes_cache(const char* _vcname__)
    : Vnodes_cache(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vnodes_cache::~Vnodes_cache() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vnodes_cache___024root___eval_debug_assertions(Vnodes_cache___024root* vlSelf);
#endif  // VL_DEBUG
void Vnodes_cache___024root___eval_static(Vnodes_cache___024root* vlSelf);
void Vnodes_cache___024root___eval_initial(Vnodes_cache___024root* vlSelf);
void Vnodes_cache___024root___eval_settle(Vnodes_cache___024root* vlSelf);
void Vnodes_cache___024root___eval(Vnodes_cache___024root* vlSelf);

void Vnodes_cache::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vnodes_cache::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vnodes_cache___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vnodes_cache___024root___eval_static(&(vlSymsp->TOP));
        Vnodes_cache___024root___eval_initial(&(vlSymsp->TOP));
        Vnodes_cache___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vnodes_cache___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vnodes_cache::eventsPending() { return false; }

uint64_t Vnodes_cache::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vnodes_cache::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vnodes_cache___024root___eval_final(Vnodes_cache___024root* vlSelf);

VL_ATTR_COLD void Vnodes_cache::final() {
    Vnodes_cache___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vnodes_cache::hierName() const { return vlSymsp->name(); }
const char* Vnodes_cache::modelName() const { return "Vnodes_cache"; }
unsigned Vnodes_cache::threads() const { return 1; }
void Vnodes_cache::prepareClone() const { contextp()->prepareClone(); }
void Vnodes_cache::atClone() const {
    contextp()->threadPoolpOnClone();
}
