// Lean compiler output
// Module: Init.Control.Basic
// Imports: Init.Core
#include <lean/lean.h>
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunused-label"
#elif defined(__GNUC__) && !defined(__CLANG__)
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif
#ifdef __cplusplus
extern "C" {
#endif
lean_object* l_notM___rarg___lambda__1___boxed(lean_object*);
lean_object* l_assert___rarg(lean_object*, lean_object*, uint8_t);
lean_object* l_Init_Control_Basic___instance__4___rarg___lambda__1___boxed(lean_object*, lean_object*);
lean_object* l_control___rarg(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_guard___rarg(lean_object*, lean_object*, uint8_t);
lean_object* l_Init_Control_Basic___instance__2;
lean_object* l_controlAt___rarg(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_bool_match__1(lean_object*);
lean_object* l_controlAt(lean_object*, lean_object*);
lean_object* l_Init_Control_Basic___instance__1___rarg(lean_object*);
lean_object* l_andM_match__1___rarg(uint8_t, lean_object*, lean_object*);
lean_object* l_Functor_discard(lean_object*, lean_object*);
lean_object* l_Functor_mapRev(lean_object*);
lean_object* l_Init_Control_Basic___instance__3___rarg___lambda__4(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_orM_match__1(lean_object*);
lean_object* l_Init_Control_Basic___instance__4___rarg___lambda__2(lean_object*, lean_object*);
extern lean_object* l_Init_Prelude___instance__9___closed__1;
lean_object* l_Functor_discard___rarg(lean_object*, lean_object*);
lean_object* l_Init_Control_Basic___instance__3___rarg___lambda__5(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_when(lean_object*);
lean_object* l_optional___rarg___closed__1;
lean_object* l_andM___rarg(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_assert(lean_object*);
lean_object* l_unless___rarg___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Init_Control_Basic___instance__3___rarg___lambda__1(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_optional___rarg(lean_object*, lean_object*, lean_object*);
lean_object* l_when___rarg(lean_object*, lean_object*, uint8_t, lean_object*);
lean_object* l_bool_match__1___rarg___boxed(lean_object*, lean_object*, lean_object*);
lean_object* l_bool_match__1___rarg(uint8_t, lean_object*, lean_object*);
lean_object* l_notM___rarg___closed__1;
lean_object* l_Init_Prelude___instance__37___rarg___lambda__1(lean_object*, lean_object*, lean_object*);
lean_object* l_guard___rarg___boxed(lean_object*, lean_object*, lean_object*);
lean_object* l_orM___rarg(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_orM_match__1___rarg___boxed(lean_object*, lean_object*, lean_object*);
lean_object* l_bool___rarg___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_notM(lean_object*);
lean_object* l_bool(lean_object*, lean_object*);
lean_object* l_Init_Control_Basic___instance__4___rarg___closed__1;
lean_object* l_Init_Control_Basic___instance__4___rarg(lean_object*);
lean_object* l_Init_Control_Basic___instance__3___rarg___lambda__2(lean_object*, lean_object*, lean_object*);
lean_object* l_Functor_mapRev___rarg(lean_object*, lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Init_Control_Basic___instance__1(lean_object*, lean_object*);
lean_object* l_Init_Control_Basic___instance__3___rarg___lambda__3(lean_object*, lean_object*, lean_object*);
lean_object* l_orM___rarg___lambda__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Init_Control_Basic___instance__4___rarg___lambda__2___closed__1;
lean_object* l_optional___rarg___lambda__1(lean_object*);
lean_object* l_orM___rarg___lambda__1(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_Init_Control_Basic___instance__4___rarg___lambda__1(lean_object*, lean_object*);
lean_object* l_Init_Control_Basic___instance__3(lean_object*, lean_object*, lean_object*);
lean_object* l_andM___rarg___lambda__1___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
uint8_t l_notM___rarg___lambda__1(uint8_t);
lean_object* l_andM_match__1(lean_object*);
lean_object* l_Init_Control_Basic___instance__4(lean_object*);
lean_object* l_bool___rarg(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_orM_match__1___rarg(uint8_t, lean_object*, lean_object*);
lean_object* l_unless(lean_object*);
lean_object* l_Init_Control_Basic___instance__3___rarg(lean_object*, lean_object*);
lean_object* l_unless___rarg(lean_object*, lean_object*, uint8_t, lean_object*);
lean_object* l_andM___rarg___lambda__1(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_andM(lean_object*, lean_object*);
lean_object* l_guard(lean_object*);
lean_object* l_optional(lean_object*);
lean_object* l_orM(lean_object*, lean_object*);
lean_object* l_assert___rarg___boxed(lean_object*, lean_object*, lean_object*);
lean_object* l_control(lean_object*, lean_object*);
lean_object* l_when___rarg___boxed(lean_object*, lean_object*, lean_object*, lean_object*);
lean_object* l_andM_match__1___rarg___boxed(lean_object*, lean_object*, lean_object*);
lean_object* l_notM___rarg(lean_object*, lean_object*);
lean_object* l_Functor_mapRev___rarg(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4, lean_object* x_5) {
_start:
{
lean_object* x_6; lean_object* x_7; 
x_6 = lean_ctor_get(x_1, 0);
lean_inc(x_6);
lean_dec(x_1);
x_7 = lean_apply_4(x_6, lean_box(0), lean_box(0), x_5, x_4);
return x_7;
}
}
lean_object* l_Functor_mapRev(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lean_alloc_closure((void*)(l_Functor_mapRev___rarg), 5, 0);
return x_2;
}
}
lean_object* l_Functor_discard___rarg(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; 
x_3 = lean_ctor_get(x_1, 1);
lean_inc(x_3);
lean_dec(x_1);
x_4 = lean_box(0);
x_5 = lean_apply_4(x_3, lean_box(0), lean_box(0), x_4, x_2);
return x_5;
}
}
lean_object* l_Functor_discard(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = lean_alloc_closure((void*)(l_Functor_discard___rarg), 2, 0);
return x_3;
}
}
lean_object* l_when___rarg(lean_object* x_1, lean_object* x_2, uint8_t x_3, lean_object* x_4) {
_start:
{
if (x_3 == 0)
{
lean_object* x_5; lean_object* x_6; lean_object* x_7; 
x_5 = lean_ctor_get(x_1, 1);
lean_inc(x_5);
lean_dec(x_1);
x_6 = lean_box(0);
x_7 = lean_apply_2(x_5, lean_box(0), x_6);
return x_7;
}
else
{
lean_dec(x_1);
lean_inc(x_4);
return x_4;
}
}
}
lean_object* l_when(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lean_alloc_closure((void*)(l_when___rarg___boxed), 4, 0);
return x_2;
}
}
lean_object* l_when___rarg___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
uint8_t x_5; lean_object* x_6; 
x_5 = lean_unbox(x_3);
lean_dec(x_3);
x_6 = l_when___rarg(x_1, x_2, x_5, x_4);
lean_dec(x_4);
return x_6;
}
}
lean_object* l_unless___rarg(lean_object* x_1, lean_object* x_2, uint8_t x_3, lean_object* x_4) {
_start:
{
if (x_3 == 0)
{
lean_dec(x_1);
lean_inc(x_4);
return x_4;
}
else
{
lean_object* x_5; lean_object* x_6; lean_object* x_7; 
x_5 = lean_ctor_get(x_1, 1);
lean_inc(x_5);
lean_dec(x_1);
x_6 = lean_box(0);
x_7 = lean_apply_2(x_5, lean_box(0), x_6);
return x_7;
}
}
}
lean_object* l_unless(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lean_alloc_closure((void*)(l_unless___rarg___boxed), 4, 0);
return x_2;
}
}
lean_object* l_unless___rarg___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
uint8_t x_5; lean_object* x_6; 
x_5 = lean_unbox(x_3);
lean_dec(x_3);
x_6 = l_unless___rarg(x_1, x_2, x_5, x_4);
lean_dec(x_4);
return x_6;
}
}
lean_object* l_Init_Control_Basic___instance__1___rarg(lean_object* x_1) {
_start:
{
lean_object* x_2; lean_object* x_3; 
x_2 = lean_ctor_get(x_1, 2);
lean_inc(x_2);
lean_dec(x_1);
x_3 = lean_apply_1(x_2, lean_box(0));
return x_3;
}
}
lean_object* l_Init_Control_Basic___instance__1(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = lean_alloc_closure((void*)(l_Init_Control_Basic___instance__1___rarg), 1, 0);
return x_3;
}
}
lean_object* l_guard___rarg(lean_object* x_1, lean_object* x_2, uint8_t x_3) {
_start:
{
if (x_3 == 0)
{
lean_object* x_4; lean_object* x_5; 
x_4 = lean_ctor_get(x_1, 1);
lean_inc(x_4);
lean_dec(x_1);
x_5 = lean_apply_1(x_4, lean_box(0));
return x_5;
}
else
{
lean_object* x_6; lean_object* x_7; lean_object* x_8; lean_object* x_9; 
x_6 = lean_ctor_get(x_1, 0);
lean_inc(x_6);
lean_dec(x_1);
x_7 = lean_ctor_get(x_6, 1);
lean_inc(x_7);
lean_dec(x_6);
x_8 = lean_box(0);
x_9 = lean_apply_2(x_7, lean_box(0), x_8);
return x_9;
}
}
}
lean_object* l_guard(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lean_alloc_closure((void*)(l_guard___rarg___boxed), 3, 0);
return x_2;
}
}
lean_object* l_guard___rarg___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
uint8_t x_4; lean_object* x_5; 
x_4 = lean_unbox(x_3);
lean_dec(x_3);
x_5 = l_guard___rarg(x_1, x_2, x_4);
return x_5;
}
}
lean_object* l_assert___rarg(lean_object* x_1, lean_object* x_2, uint8_t x_3) {
_start:
{
if (x_3 == 0)
{
lean_object* x_4; lean_object* x_5; 
x_4 = lean_ctor_get(x_1, 1);
lean_inc(x_4);
lean_dec(x_1);
x_5 = lean_apply_1(x_4, lean_box(0));
return x_5;
}
else
{
lean_object* x_6; lean_object* x_7; lean_object* x_8; 
x_6 = lean_ctor_get(x_1, 0);
lean_inc(x_6);
lean_dec(x_1);
x_7 = lean_ctor_get(x_6, 1);
lean_inc(x_7);
lean_dec(x_6);
x_8 = lean_apply_2(x_7, lean_box(0), lean_box(0));
return x_8;
}
}
}
lean_object* l_assert(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lean_alloc_closure((void*)(l_assert___rarg___boxed), 3, 0);
return x_2;
}
}
lean_object* l_assert___rarg___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
uint8_t x_4; lean_object* x_5; 
x_4 = lean_unbox(x_3);
lean_dec(x_3);
x_5 = l_assert___rarg(x_1, x_2, x_4);
return x_5;
}
}
lean_object* l_optional___rarg___lambda__1(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lean_alloc_ctor(1, 1, 0);
lean_ctor_set(x_2, 0, x_1);
return x_2;
}
}
static lean_object* _init_l_optional___rarg___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_alloc_closure((void*)(l_optional___rarg___lambda__1), 1, 0);
return x_1;
}
}
lean_object* l_optional___rarg(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
lean_object* x_4; lean_object* x_5; lean_object* x_6; lean_object* x_7; lean_object* x_8; lean_object* x_9; lean_object* x_10; lean_object* x_11; lean_object* x_12; lean_object* x_13; 
x_4 = lean_ctor_get(x_1, 2);
lean_inc(x_4);
x_5 = lean_ctor_get(x_1, 0);
lean_inc(x_5);
lean_dec(x_1);
x_6 = lean_ctor_get(x_5, 0);
lean_inc(x_6);
x_7 = lean_ctor_get(x_6, 0);
lean_inc(x_7);
lean_dec(x_6);
x_8 = l_optional___rarg___closed__1;
x_9 = lean_apply_4(x_7, lean_box(0), lean_box(0), x_8, x_3);
x_10 = lean_ctor_get(x_5, 1);
lean_inc(x_10);
lean_dec(x_5);
x_11 = lean_box(0);
x_12 = lean_apply_2(x_10, lean_box(0), x_11);
x_13 = lean_apply_3(x_4, lean_box(0), x_9, x_12);
return x_13;
}
}
lean_object* l_optional(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lean_alloc_closure((void*)(l_optional___rarg), 3, 0);
return x_2;
}
}
static lean_object* _init_l_Init_Control_Basic___instance__2() {
_start:
{
lean_object* x_1; 
x_1 = l_Init_Prelude___instance__9___closed__1;
return x_1;
}
}
lean_object* l_bool_match__1___rarg(uint8_t x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
if (x_1 == 0)
{
lean_object* x_4; lean_object* x_5; 
lean_dec(x_2);
x_4 = lean_box(0);
x_5 = lean_apply_1(x_3, x_4);
return x_5;
}
else
{
lean_object* x_6; lean_object* x_7; 
lean_dec(x_3);
x_6 = lean_box(0);
x_7 = lean_apply_1(x_2, x_6);
return x_7;
}
}
}
lean_object* l_bool_match__1(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lean_alloc_closure((void*)(l_bool_match__1___rarg___boxed), 3, 0);
return x_2;
}
}
lean_object* l_bool_match__1___rarg___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
uint8_t x_4; lean_object* x_5; 
x_4 = lean_unbox(x_1);
lean_dec(x_1);
x_5 = l_bool_match__1___rarg(x_4, x_2, x_3);
return x_5;
}
}
lean_object* l_bool___rarg(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; uint8_t x_6; 
x_5 = lean_apply_1(x_1, x_4);
x_6 = lean_unbox(x_5);
lean_dec(x_5);
if (x_6 == 0)
{
lean_inc(x_2);
return x_2;
}
else
{
lean_inc(x_3);
return x_3;
}
}
}
lean_object* l_bool(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = lean_alloc_closure((void*)(l_bool___rarg___boxed), 4, 0);
return x_3;
}
}
lean_object* l_bool___rarg___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; 
x_5 = l_bool___rarg(x_1, x_2, x_3, x_4);
lean_dec(x_3);
lean_dec(x_2);
return x_5;
}
}
lean_object* l_orM_match__1___rarg(uint8_t x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
if (x_1 == 0)
{
lean_object* x_4; lean_object* x_5; 
lean_dec(x_2);
x_4 = lean_box(0);
x_5 = lean_apply_1(x_3, x_4);
return x_5;
}
else
{
lean_object* x_6; lean_object* x_7; 
lean_dec(x_3);
x_6 = lean_box(0);
x_7 = lean_apply_1(x_2, x_6);
return x_7;
}
}
}
lean_object* l_orM_match__1(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lean_alloc_closure((void*)(l_orM_match__1___rarg___boxed), 3, 0);
return x_2;
}
}
lean_object* l_orM_match__1___rarg___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
uint8_t x_4; lean_object* x_5; 
x_4 = lean_unbox(x_1);
lean_dec(x_1);
x_5 = l_orM_match__1___rarg(x_4, x_2, x_3);
return x_5;
}
}
lean_object* l_orM___rarg___lambda__1(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; uint8_t x_6; 
lean_inc(x_4);
x_5 = lean_apply_1(x_1, x_4);
x_6 = lean_unbox(x_5);
lean_dec(x_5);
if (x_6 == 0)
{
lean_dec(x_4);
lean_dec(x_3);
lean_inc(x_2);
return x_2;
}
else
{
lean_object* x_7; lean_object* x_8; lean_object* x_9; 
x_7 = lean_ctor_get(x_3, 0);
lean_inc(x_7);
lean_dec(x_3);
x_8 = lean_ctor_get(x_7, 1);
lean_inc(x_8);
lean_dec(x_7);
x_9 = lean_apply_2(x_8, lean_box(0), x_4);
return x_9;
}
}
}
lean_object* l_orM___rarg(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; lean_object* x_6; lean_object* x_7; 
x_5 = lean_ctor_get(x_1, 1);
lean_inc(x_5);
x_6 = lean_alloc_closure((void*)(l_orM___rarg___lambda__1___boxed), 4, 3);
lean_closure_set(x_6, 0, x_2);
lean_closure_set(x_6, 1, x_4);
lean_closure_set(x_6, 2, x_1);
x_7 = lean_apply_4(x_5, lean_box(0), lean_box(0), x_3, x_6);
return x_7;
}
}
lean_object* l_orM(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = lean_alloc_closure((void*)(l_orM___rarg), 4, 0);
return x_3;
}
}
lean_object* l_orM___rarg___lambda__1___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; 
x_5 = l_orM___rarg___lambda__1(x_1, x_2, x_3, x_4);
lean_dec(x_2);
return x_5;
}
}
lean_object* l_andM_match__1___rarg(uint8_t x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
if (x_1 == 0)
{
lean_object* x_4; lean_object* x_5; 
lean_dec(x_2);
x_4 = lean_box(0);
x_5 = lean_apply_1(x_3, x_4);
return x_5;
}
else
{
lean_object* x_6; lean_object* x_7; 
lean_dec(x_3);
x_6 = lean_box(0);
x_7 = lean_apply_1(x_2, x_6);
return x_7;
}
}
}
lean_object* l_andM_match__1(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lean_alloc_closure((void*)(l_andM_match__1___rarg___boxed), 3, 0);
return x_2;
}
}
lean_object* l_andM_match__1___rarg___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
uint8_t x_4; lean_object* x_5; 
x_4 = lean_unbox(x_1);
lean_dec(x_1);
x_5 = l_andM_match__1___rarg(x_4, x_2, x_3);
return x_5;
}
}
lean_object* l_andM___rarg___lambda__1(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; uint8_t x_6; 
lean_inc(x_4);
x_5 = lean_apply_1(x_1, x_4);
x_6 = lean_unbox(x_5);
lean_dec(x_5);
if (x_6 == 0)
{
lean_object* x_7; lean_object* x_8; lean_object* x_9; 
x_7 = lean_ctor_get(x_2, 0);
lean_inc(x_7);
lean_dec(x_2);
x_8 = lean_ctor_get(x_7, 1);
lean_inc(x_8);
lean_dec(x_7);
x_9 = lean_apply_2(x_8, lean_box(0), x_4);
return x_9;
}
else
{
lean_dec(x_4);
lean_dec(x_2);
lean_inc(x_3);
return x_3;
}
}
}
lean_object* l_andM___rarg(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; lean_object* x_6; lean_object* x_7; 
x_5 = lean_ctor_get(x_1, 1);
lean_inc(x_5);
x_6 = lean_alloc_closure((void*)(l_andM___rarg___lambda__1___boxed), 4, 3);
lean_closure_set(x_6, 0, x_2);
lean_closure_set(x_6, 1, x_1);
lean_closure_set(x_6, 2, x_4);
x_7 = lean_apply_4(x_5, lean_box(0), lean_box(0), x_3, x_6);
return x_7;
}
}
lean_object* l_andM(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = lean_alloc_closure((void*)(l_andM___rarg), 4, 0);
return x_3;
}
}
lean_object* l_andM___rarg___lambda__1___boxed(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; 
x_5 = l_andM___rarg___lambda__1(x_1, x_2, x_3, x_4);
lean_dec(x_3);
return x_5;
}
}
uint8_t l_notM___rarg___lambda__1(uint8_t x_1) {
_start:
{
if (x_1 == 0)
{
uint8_t x_2; 
x_2 = 1;
return x_2;
}
else
{
uint8_t x_3; 
x_3 = 0;
return x_3;
}
}
}
static lean_object* _init_l_notM___rarg___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_alloc_closure((void*)(l_notM___rarg___lambda__1___boxed), 1, 0);
return x_1;
}
}
lean_object* l_notM___rarg(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; lean_object* x_6; 
x_3 = lean_ctor_get(x_1, 0);
lean_inc(x_3);
lean_dec(x_1);
x_4 = lean_ctor_get(x_3, 0);
lean_inc(x_4);
lean_dec(x_3);
x_5 = l_notM___rarg___closed__1;
x_6 = lean_apply_4(x_4, lean_box(0), lean_box(0), x_5, x_2);
return x_6;
}
}
lean_object* l_notM(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lean_alloc_closure((void*)(l_notM___rarg), 2, 0);
return x_2;
}
}
lean_object* l_notM___rarg___lambda__1___boxed(lean_object* x_1) {
_start:
{
uint8_t x_2; uint8_t x_3; lean_object* x_4; 
x_2 = lean_unbox(x_1);
lean_dec(x_1);
x_3 = l_notM___rarg___lambda__1(x_2);
x_4 = lean_box(x_3);
return x_4;
}
}
lean_object* l_Init_Control_Basic___instance__3___rarg___lambda__1(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; lean_object* x_6; 
x_5 = lean_apply_2(x_1, lean_box(0), x_4);
x_6 = lean_apply_2(x_2, lean_box(0), x_5);
return x_6;
}
}
lean_object* l_Init_Control_Basic___instance__3___rarg___lambda__2(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
lean_object* x_4; lean_object* x_5; 
x_4 = lean_alloc_closure((void*)(l_Init_Control_Basic___instance__3___rarg___lambda__1), 4, 2);
lean_closure_set(x_4, 0, x_1);
lean_closure_set(x_4, 1, x_3);
x_5 = lean_apply_1(x_2, x_4);
return x_5;
}
}
lean_object* l_Init_Control_Basic___instance__3___rarg___lambda__3(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
lean_object* x_4; lean_object* x_5; lean_object* x_6; 
x_4 = lean_ctor_get(x_1, 0);
lean_inc(x_4);
lean_dec(x_1);
x_5 = lean_alloc_closure((void*)(l_Init_Control_Basic___instance__3___rarg___lambda__2), 3, 2);
lean_closure_set(x_5, 0, x_3);
lean_closure_set(x_5, 1, x_2);
x_6 = lean_apply_2(x_4, lean_box(0), x_5);
return x_6;
}
}
lean_object* l_Init_Control_Basic___instance__3___rarg___lambda__4(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; lean_object* x_6; lean_object* x_7; 
x_5 = lean_ctor_get(x_1, 0);
lean_inc(x_5);
lean_dec(x_1);
x_6 = lean_alloc_closure((void*)(l_Init_Control_Basic___instance__3___rarg___lambda__3), 3, 2);
lean_closure_set(x_6, 0, x_2);
lean_closure_set(x_6, 1, x_4);
x_7 = lean_apply_2(x_5, lean_box(0), x_6);
return x_7;
}
}
lean_object* l_Init_Control_Basic___instance__3___rarg___lambda__5(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; lean_object* x_6; lean_object* x_7; lean_object* x_8; 
x_5 = lean_ctor_get(x_1, 1);
lean_inc(x_5);
lean_dec(x_1);
x_6 = lean_ctor_get(x_2, 1);
lean_inc(x_6);
lean_dec(x_2);
x_7 = lean_apply_2(x_6, lean_box(0), x_4);
x_8 = lean_apply_2(x_5, lean_box(0), x_7);
return x_8;
}
}
lean_object* l_Init_Control_Basic___instance__3___rarg(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; lean_object* x_5; 
lean_inc(x_1);
lean_inc(x_2);
x_3 = lean_alloc_closure((void*)(l_Init_Control_Basic___instance__3___rarg___lambda__4), 4, 2);
lean_closure_set(x_3, 0, x_2);
lean_closure_set(x_3, 1, x_1);
x_4 = lean_alloc_closure((void*)(l_Init_Control_Basic___instance__3___rarg___lambda__5), 4, 2);
lean_closure_set(x_4, 0, x_2);
lean_closure_set(x_4, 1, x_1);
x_5 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_5, 0, x_3);
lean_ctor_set(x_5, 1, x_4);
return x_5;
}
}
lean_object* l_Init_Control_Basic___instance__3(lean_object* x_1, lean_object* x_2, lean_object* x_3) {
_start:
{
lean_object* x_4; 
x_4 = lean_alloc_closure((void*)(l_Init_Control_Basic___instance__3___rarg), 2, 0);
return x_4;
}
}
lean_object* l_Init_Control_Basic___instance__4___rarg___lambda__1(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_inc(x_2);
return x_2;
}
}
static lean_object* _init_l_Init_Control_Basic___instance__4___rarg___lambda__2___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_alloc_closure((void*)(l_Init_Control_Basic___instance__4___rarg___lambda__1___boxed), 2, 0);
return x_1;
}
}
lean_object* l_Init_Control_Basic___instance__4___rarg___lambda__2(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; lean_object* x_4; 
x_3 = l_Init_Control_Basic___instance__4___rarg___lambda__2___closed__1;
x_4 = lean_apply_1(x_2, x_3);
return x_4;
}
}
static lean_object* _init_l_Init_Control_Basic___instance__4___rarg___closed__1() {
_start:
{
lean_object* x_1; 
x_1 = lean_alloc_closure((void*)(l_Init_Control_Basic___instance__4___rarg___lambda__2), 2, 0);
return x_1;
}
}
lean_object* l_Init_Control_Basic___instance__4___rarg(lean_object* x_1) {
_start:
{
lean_object* x_2; lean_object* x_3; lean_object* x_4; 
x_2 = lean_alloc_closure((void*)(l_Init_Prelude___instance__37___rarg___lambda__1), 3, 1);
lean_closure_set(x_2, 0, x_1);
x_3 = l_Init_Control_Basic___instance__4___rarg___closed__1;
x_4 = lean_alloc_ctor(0, 2, 0);
lean_ctor_set(x_4, 0, x_3);
lean_ctor_set(x_4, 1, x_2);
return x_4;
}
}
lean_object* l_Init_Control_Basic___instance__4(lean_object* x_1) {
_start:
{
lean_object* x_2; 
x_2 = lean_alloc_closure((void*)(l_Init_Control_Basic___instance__4___rarg), 1, 0);
return x_2;
}
}
lean_object* l_Init_Control_Basic___instance__4___rarg___lambda__1___boxed(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = l_Init_Control_Basic___instance__4___rarg___lambda__1(x_1, x_2);
lean_dec(x_2);
return x_3;
}
}
lean_object* l_controlAt___rarg(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; lean_object* x_6; lean_object* x_7; lean_object* x_8; lean_object* x_9; 
x_5 = lean_ctor_get(x_1, 0);
lean_inc(x_5);
x_6 = lean_apply_2(x_5, lean_box(0), x_4);
x_7 = lean_ctor_get(x_1, 1);
lean_inc(x_7);
lean_dec(x_1);
x_8 = lean_apply_1(x_7, lean_box(0));
x_9 = lean_apply_4(x_2, lean_box(0), lean_box(0), x_6, x_8);
return x_9;
}
}
lean_object* l_controlAt(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = lean_alloc_closure((void*)(l_controlAt___rarg), 4, 0);
return x_3;
}
}
lean_object* l_control___rarg(lean_object* x_1, lean_object* x_2, lean_object* x_3, lean_object* x_4) {
_start:
{
lean_object* x_5; lean_object* x_6; lean_object* x_7; lean_object* x_8; lean_object* x_9; 
x_5 = lean_ctor_get(x_1, 0);
lean_inc(x_5);
x_6 = lean_apply_2(x_5, lean_box(0), x_4);
x_7 = lean_ctor_get(x_1, 1);
lean_inc(x_7);
lean_dec(x_1);
x_8 = lean_apply_1(x_7, lean_box(0));
x_9 = lean_apply_4(x_2, lean_box(0), lean_box(0), x_6, x_8);
return x_9;
}
}
lean_object* l_control(lean_object* x_1, lean_object* x_2) {
_start:
{
lean_object* x_3; 
x_3 = lean_alloc_closure((void*)(l_control___rarg), 4, 0);
return x_3;
}
}
lean_object* initialize_Init_Core(lean_object*);
static bool _G_initialized = false;
lean_object* initialize_Init_Control_Basic(lean_object* w) {
lean_object * res;
if (_G_initialized) return lean_io_result_mk_ok(lean_box(0));
_G_initialized = true;
res = initialize_Init_Core(lean_io_mk_world());
if (lean_io_result_is_error(res)) return res;
lean_dec_ref(res);
l_optional___rarg___closed__1 = _init_l_optional___rarg___closed__1();
lean_mark_persistent(l_optional___rarg___closed__1);
l_Init_Control_Basic___instance__2 = _init_l_Init_Control_Basic___instance__2();
lean_mark_persistent(l_Init_Control_Basic___instance__2);
l_notM___rarg___closed__1 = _init_l_notM___rarg___closed__1();
lean_mark_persistent(l_notM___rarg___closed__1);
l_Init_Control_Basic___instance__4___rarg___lambda__2___closed__1 = _init_l_Init_Control_Basic___instance__4___rarg___lambda__2___closed__1();
lean_mark_persistent(l_Init_Control_Basic___instance__4___rarg___lambda__2___closed__1);
l_Init_Control_Basic___instance__4___rarg___closed__1 = _init_l_Init_Control_Basic___instance__4___rarg___closed__1();
lean_mark_persistent(l_Init_Control_Basic___instance__4___rarg___closed__1);
return lean_io_result_mk_ok(lean_box(0));
}
#ifdef __cplusplus
}
#endif