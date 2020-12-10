//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "p1.h"
#include "redirect_io.h"
using namespace std;

TEST_CASE("Pregunta #1") {
    execute_test("test_1.in", pregunta_1_case_1);
}