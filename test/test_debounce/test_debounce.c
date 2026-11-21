
#include <stdio.h>
#include "unity.h"
#include "input/debounce.h"

void test_stable_press(void)
{
    Debounce button;
    debounce_init(&button, false, 0, 30);

    TEST_ASSERT_EQUAL(BUTTON_EVENT_NONE,
                      debounce_update(&button, true, 10));
    TEST_ASSERT_EQUAL(BUTTON_EVENT_NONE,
                      debounce_update(&button, true, 20));
    TEST_ASSERT_EQUAL(BUTTON_EVENT_PRESSED,
                      debounce_update(&button, true, 40));
}

void test_stable_release(void)
{
    Debounce button;
    debounce_init(&button, true, 0, 30);

    TEST_ASSERT_EQUAL(BUTTON_EVENT_NONE,
                      debounce_update(&button, false, 10));
    TEST_ASSERT_EQUAL(BUTTON_EVENT_RELEASED,
                      debounce_update(&button, false, 40));
}

void test_bouncing(void)
{
    Debounce button;
    debounce_init(&button, false, 0, 30);

    TEST_ASSERT_EQUAL(BUTTON_EVENT_NONE,
                      debounce_update(&button, true, 10));
    TEST_ASSERT_EQUAL(BUTTON_EVENT_NONE,
                      debounce_update(&button, false, 15));
    TEST_ASSERT_EQUAL(BUTTON_EVENT_NONE,
                      debounce_update(&button, true, 20));
    TEST_ASSERT_EQUAL(BUTTON_EVENT_NONE,
                      debounce_update(&button, false, 25));
    TEST_ASSERT_EQUAL(BUTTON_EVENT_NONE,
                      debounce_update(&button, true, 30));

    TEST_ASSERT_EQUAL(BUTTON_EVENT_PRESSED,
                      debounce_update(&button, true, 60));
}

void test_short_press(void)
{
    Debounce button;
    debounce_init(&button, false, 0, 30);

    TEST_ASSERT_EQUAL(BUTTON_EVENT_NONE,
                      debounce_update(&button, true, 10));
    TEST_ASSERT_EQUAL(BUTTON_EVENT_NONE,
                      debounce_update(&button, false, 20));
    TEST_ASSERT_EQUAL(BUTTON_EVENT_NONE,
                      debounce_update(&button, false, 50));
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_stable_press);
    RUN_TEST(test_stable_release);
    RUN_TEST(test_bouncing);
    RUN_TEST(test_short_press);

    return UNITY_END();
}
