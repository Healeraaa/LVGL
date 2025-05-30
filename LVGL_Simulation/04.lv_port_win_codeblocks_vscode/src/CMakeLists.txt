SET(SOURCES screens/ui_Screen1.c
    screens/ui_Screen2.c
    ui.c
    ui_helpers.c
    fonts/ui_font_ALIBABA16.c
    fonts/ui_font_ALIBABA32.c
    fonts/ui_font_iconfont32.c)

add_library(ui ${SOURCES})
