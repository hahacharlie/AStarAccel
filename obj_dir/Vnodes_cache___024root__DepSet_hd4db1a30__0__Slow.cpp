// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vnodes_cache.h for the primary calling header

#include "Vnodes_cache__pch.h"
#include "Vnodes_cache___024root.h"

VL_ATTR_COLD void Vnodes_cache___024root___eval_static(Vnodes_cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vnodes_cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnodes_cache___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vnodes_cache___024root___eval_initial(Vnodes_cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vnodes_cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnodes_cache___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = vlSelf->rst;
}

VL_ATTR_COLD void Vnodes_cache___024root___eval_final(Vnodes_cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vnodes_cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnodes_cache___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vnodes_cache___024root___dump_triggers__stl(Vnodes_cache___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vnodes_cache___024root___eval_phase__stl(Vnodes_cache___024root* vlSelf);

VL_ATTR_COLD void Vnodes_cache___024root___eval_settle(Vnodes_cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vnodes_cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnodes_cache___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vnodes_cache___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("nodes_cache.sv", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vnodes_cache___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vnodes_cache___024root___dump_triggers__stl(Vnodes_cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vnodes_cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnodes_cache___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ vlSelf->__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vnodes_cache___024root___ico_sequent__TOP__0(Vnodes_cache___024root* vlSelf);

VL_ATTR_COLD void Vnodes_cache___024root___eval_stl(Vnodes_cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vnodes_cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnodes_cache___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vnodes_cache___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vnodes_cache___024root___eval_triggers__stl(Vnodes_cache___024root* vlSelf);

VL_ATTR_COLD bool Vnodes_cache___024root___eval_phase__stl(Vnodes_cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vnodes_cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnodes_cache___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vnodes_cache___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vnodes_cache___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vnodes_cache___024root___dump_triggers__ico(Vnodes_cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vnodes_cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnodes_cache___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ vlSelf->__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vnodes_cache___024root___dump_triggers__act(Vnodes_cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vnodes_cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnodes_cache___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ vlSelf->__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk or posedge rst)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vnodes_cache___024root___dump_triggers__nba(Vnodes_cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vnodes_cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnodes_cache___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ vlSelf->__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk or posedge rst)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vnodes_cache___024root___ctor_var_reset(Vnodes_cache___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vnodes_cache__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vnodes_cache___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->valid = VL_RAND_RESET_I(8);
    vlSelf->write = VL_RAND_RESET_I(8);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->address[__Vi0] = VL_RAND_RESET_I(10);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        VL_RAND_RESET_W(226, vlSelf->data_in[__Vi0]);
    }
    vlSelf->hit = VL_RAND_RESET_I(8);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        VL_RAND_RESET_W(226, vlSelf->data_out[__Vi0]);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 2; ++__Vi1) {
            VL_RAND_RESET_W(233, vlSelf->nodes_cache__DOT__node_cache[__Vi0][__Vi1]);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->nodes_cache__DOT__index[__Vi0] = VL_RAND_RESET_I(5);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->nodes_cache__DOT__tag[__Vi0] = VL_RAND_RESET_I(5);
    }
    vlSelf->nodes_cache__DOT__unnamedblk4__DOT__unnamedblk5__DOT__set_idx = VL_RAND_RESET_I(5);
    vlSelf->nodes_cache__DOT__unnamedblk4__DOT__unnamedblk5__DOT__unnamedblk7__DOT__lru_way = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = VL_RAND_RESET_I(1);
}
