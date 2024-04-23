// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vnodes_cache.h for the primary calling header

#include "Vnodes_cache__pch.h"
#include "Vnodes_cache__Syms.h"
#include "Vnodes_cache___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vnodes_cache___024root___dump_triggers__stl(Vnodes_cache___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vnodes_cache___024root___eval_triggers__stl(Vnodes_cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vnodes_cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnodes_cache___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vnodes_cache___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
