#include "my_gui.h"
#include "lvgl.h"

// 字体声明（确保启用这些字体）
LV_FONT_DECLARE(lv_font_montserrat_24);  // 24px的蒙特塞拉特字体
LV_FONT_DECLARE(lv_font_montserrat_36);  // 36px的蒙特塞拉特字体

// 现代配色方案
#define PRIMARY_COLOR    lv_color_hex(0x2196F3)  // 主蓝色（用于状态栏和部分元素）
#define SECONDARY_COLOR  lv_color_hex(0x4CAF50)  // 健康绿色（不再用于渐变色）
#define BACKGROUND_COLOR lv_color_hex(0xF5F5F5)  // 浅灰背景色
#define CARD_COLOR       lv_color_hex(0xFFFFFF)  // 纯白卡片背景
#define TEXT_SECONDARY   lv_color_hex(0x666666)  // 次级文字颜色（灰色）


static int16_t val = 0;                         /* 当前值 */

static const lv_font_t *font;                   /* 定义字体 */

static lv_obj_t *label_load;                    /* 加载标题标签 */
static lv_obj_t *label_per;                     /* 百分比标签 */
static lv_obj_t *bar;                           /* 进度条 */
static lv_obj_t *label_speed;                           /* 进度条 */
static int32_t speed_val = 0;       /* 速度值 */
static lv_obj_t *btn_speed_down;
/**
 * @brief  定时器回调
 * @param  *timer ：该定时器相关的数据
 * @return 无
 */
static void timer_cb(lv_timer_t *timer)
{
    if(val < 100)                                                           /* 当前值小于100 */
    {
        val ++;
        lv_bar_set_value(bar, val, LV_ANIM_ON);                             /* 设置当前值 */
        lv_label_set_text_fmt(label_per, "%d %%", lv_bar_get_value(bar));   /* 获取当前值，更新显示 */
    }
    else                                                                    /* 当前值大于等于100 */
    {
        lv_label_set_text(label_per, "finished!");                          /* 加载完成 */
    }
}

/**
 * @brief  加载提示标签
 * @param  无
 * @return 无
 */
static void lv_example_label(void)
{

        font = &lv_font_montserrat_20;


    /* 加载标题标签 */
    label_load = lv_label_create(lv_scr_act());
    lv_label_set_text(label_load, "LOADING...");
    lv_obj_set_style_text_font(label_load, font, LV_STATE_DEFAULT);
    lv_obj_align(label_load, LV_ALIGN_CENTER, 0, -390 / 10 );

    /* 百分比标签 */
    label_per = lv_label_create(lv_scr_act());
    lv_label_set_text(label_per, "%0");
    lv_obj_set_style_text_font(label_per, font, LV_STATE_DEFAULT);
    lv_obj_align(label_per, LV_ALIGN_CENTER, 0, 390 / 10 );
}

/**
 * @brief  加载进度条
 * @param  无
 * @return 无
 */
static void lv_example_bar(void)
{
    bar = lv_bar_create(lv_scr_act());                            /* 创建进度条 */
    lv_obj_set_align(bar, LV_ALIGN_CENTER);                       /* 设置位置 */
    lv_obj_set_size(bar, 1000 * 3 / 5, 20);                         /* 设置大小 */
    lv_obj_set_style_anim_time(bar, 100, LV_STATE_DEFAULT);       /* 设置动画时间 */
    lv_timer_create(timer_cb, 100, NULL);                         /* 初始化定时器 */
}



static void lv_example_btn_down(void)
{
    btn_speed_down = lv_btn_create(lv_scr_act());                                   /* 创建加速按钮 */
    lv_obj_set_size(btn_speed_down, 1000 / 10, 1000 / 14);     /* 设置按钮大小 */
    lv_obj_align(btn_speed_down, LV_ALIGN_CENTER, 0, 100);                            /* 设置按钮位置 */


    lv_obj_t* label = lv_label_create(btn_speed_down);                              /* 创建减速按钮标签 */
    lv_obj_set_style_text_font(label, font, LV_PART_MAIN);                          /* 设置字体 */
    lv_label_set_text(label, "Health");
    lv_obj_set_style_text_color(label, lv_color_hex(0x000000), LV_PART_MAIN);                                   /* 设置标签文本 */
    lv_obj_set_align(label,LV_ALIGN_CENTER);
     lv_obj_set_style_bg_color(btn_speed_down, lv_color_hex(0xdefee6), LV_PART_MAIN);                                      /* 设置标签位置 */
}





void my_gui(void)
{
    // 1. 初始化背景
    lv_obj_set_style_bg_color(lv_scr_act(), BACKGROUND_COLOR, LV_PART_MAIN);  // 设置背景颜色
    lv_obj_set_style_bg_opa(lv_scr_act(), LV_OPA_COVER, LV_PART_MAIN);  // 设置背景透明度为完全不透明

    // 2. 创建状态栏（Material Design风格）
    lv_obj_t * status_bar = lv_obj_create(lv_scr_act());  // 创建状态栏对象
    lv_obj_remove_style_all(status_bar);  // 移除状态栏的所有默认样式
    lv_obj_set_size(status_bar, LV_PCT(100), 48);  // 设置状态栏的宽度为100%、高度为48px
    lv_obj_set_style_bg_color(status_bar, PRIMARY_COLOR, LV_PART_MAIN);  // 设置状态栏的背景颜色为主蓝色
    lv_obj_set_style_pad_top(status_bar, 12, LV_PART_MAIN);  // 设置状态栏顶部内边距为12px，使其下移

    // 3. 创建时间卡片（现代化设计）
    lv_obj_t * time_card = lv_obj_create(lv_scr_act());  // 创建时间卡片对象
    lv_obj_remove_style_all(time_card);  // 移除时间卡片的所有默认样式
    lv_obj_set_size(time_card, 320, 180);  // 设置卡片的大小为320x180px
    lv_obj_align(time_card, LV_ALIGN_TOP_MID, 0, 250);  // 将卡片对齐到屏幕顶部中央，偏移80px

    // 卡片视觉样式设置
    lv_obj_set_style_bg_color(time_card, CARD_COLOR, LV_PART_MAIN);  // 设置卡片背景颜色为纯白色
    lv_obj_set_style_radius(time_card, 16, LV_PART_MAIN);  // 设置卡片圆角为16px
    lv_obj_set_style_shadow_width(time_card, 32, LV_PART_MAIN);  // 设置卡片阴影宽度为32px
    lv_obj_set_style_shadow_ofs_y(time_card, 8, LV_PART_MAIN);  // 设置卡片阴影垂直偏移量为8px
    lv_obj_set_style_shadow_color(time_card, lv_color_hex(0x88888833), LV_PART_MAIN);  // 设置卡片阴影颜色为半透明的灰色

    // 4. 时间显示（主视觉）
    lv_obj_t * time_label = lv_label_create(time_card);  // 在时间卡片中创建一个标签来显示时间
    lv_obj_set_style_text_font(time_label, &lv_font_montserrat_36, LV_PART_MAIN);  // 设置字体为36px的蒙特塞拉特字体
    lv_obj_set_style_text_color(time_label, PRIMARY_COLOR, LV_PART_MAIN);  // 设置字体颜色为主蓝色
    lv_label_set_text(time_label, "14:32");  // 设置时间显示为"14:32"
    lv_obj_align(time_label, LV_ALIGN_CENTER, 0, -24);  // 将时间标签对齐到卡片中心，稍微上移24px

    // 5. 日期显示（英文格式）
    lv_obj_t * date_label = lv_label_create(time_card);  // 在时间卡片中创建一个标签来显示日期
    lv_label_set_text(date_label, "Feb 24, 2025");  // 设置日期为"Feb 24, 2025"
    lv_obj_set_style_text_font(date_label, &lv_font_montserrat_24, LV_PART_MAIN);  // 设置字体为24px的蒙特塞拉特字体
    lv_obj_set_style_text_color(date_label, TEXT_SECONDARY, LV_PART_MAIN);  // 设置字体颜色为次级文字灰色
    lv_obj_align(date_label, LV_ALIGN_BOTTOM_MID, 0, -16);  // 将日期标签对齐到卡片底部中央，偏移-16px

    // 6. 健康状态卡片
    lv_obj_t * health_panel = lv_obj_create(lv_scr_act());  // 创建健康状态卡片对象
    lv_obj_remove_style_all(health_panel);  // 移除健康状态卡片的所有默认样式
    lv_obj_set_size(health_panel, 280, 100);  // 设置健康状态卡片大小为280x100px
    lv_obj_align_to(health_panel, time_card, LV_ALIGN_OUT_BOTTOM_MID, 0, 32);  // 将健康卡片对齐到时间卡片下方，偏移32px

    // 使用蓝绿色背景代替渐变色
    lv_obj_set_style_bg_color(health_panel, lv_color_hex(0x278ddd), LV_PART_MAIN);  // 设置健康卡片的背景颜色为蓝绿色（主蓝色）
    lv_obj_set_style_radius(health_panel, 16, LV_PART_MAIN);  // 设置健康卡片的圆角为16px
//
//    // 7. 健康状态指示器布局（容器）
//    lv_obj_t * health_cont = lv_obj_create(health_panel);  // 创建一个容器，放置图标和文本
//    lv_obj_remove_style_all(health_cont);  // 移除容器的所有默认样式
//    lv_obj_set_size(health_cont, LV_PCT(100), LV_PCT(100));  // 设置容器大小为健康卡片的100%
//    lv_obj_set_flex_flow(health_cont, LV_FLEX_FLOW_ROW);  // 设置容器的布局为水平排列
//    lv_obj_set_flex_align(health_cont, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);  // 将容器内的元素居中对齐
//
//    // 8. 图标与文字组合（全英文）
//    lv_obj_t * icon = lv_label_create(health_cont);  // 创建一个标签来显示图标
//    lv_label_set_text(icon, LV_SYMBOL_OK);  // 使用内置的"OK"符号图标
//    lv_obj_set_style_text_color(icon, lv_color_white(), LV_PART_MAIN);  // 设置图标颜色为白色
//    lv_obj_set_style_text_font(icon, &lv_font_montserrat_24, LV_PART_MAIN);  // 设置图标字体为24px的蒙特塞拉特字体
//    lv_obj_set_style_pad_right(icon, 16, LV_PART_MAIN);  // 设置图标右边内边距为16px
//
//    // 创建健康状态文本标签
//    lv_obj_t * health_label = lv_label_create(health_cont);  // 创建一个标签来显示健康状态文本
//    lv_label_set_text(health_label, "Prediction: Healthy");  // 设置健康状态为"Prediction: Healthy"
//    lv_obj_set_style_text_color(health_label, lv_color_white(), LV_PART_MAIN);  // 设置文本颜色为白色
//    lv_obj_set_style_text_font(health_label, &lv_font_montserrat_24, LV_PART_MAIN);  // 设置文本字体为24px的蒙特塞拉特字体


lv_example_label();
lv_example_bar();
lv_example_btn_down();
}



