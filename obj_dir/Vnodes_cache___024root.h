// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vnodes_cache.h for the primary calling header

#ifndef VERILATED_VNODES_CACHE___024ROOT_H_
#define VERILATED_VNODES_CACHE___024ROOT_H_  // guard

#include "verilated.h"


class Vnodes_cache__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vnodes_cache___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(valid,7,0);
    VL_IN8(write,7,0);
    VL_OUT8(hit,7,0);
    CData/*4:0*/ nodes_cache__DOT__unnamedblk4__DOT__unnamedblk5__DOT__set_idx;
    CData/*0:0*/ nodes_cache__DOT__unnamedblk4__DOT__unnamedblk5__DOT__unnamedblk7__DOT__lru_way;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VL_IN16(address[8],9,0);
    VL_INW(data_in[8],225,0,8);
    VL_OUTW(data_out[8],225,0,8);
    VlUnpacked<VlUnpacked<VlWide<8>/*232:0*/, 2>, 32> nodes_cache__DOT__node_cache;
    VlUnpacked<CData/*4:0*/, 8> nodes_cache__DOT__index;
    VlUnpacked<CData/*4:0*/, 8> nodes_cache__DOT__tag;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vnodes_cache__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vnodes_cache___024root(Vnodes_cache__Syms* symsp, const char* v__name);
    ~Vnodes_cache___024root();
    VL_UNCOPYABLE(Vnodes_cache___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
