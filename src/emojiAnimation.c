#include <pebble.h>
static Window *alien_main_window;
static GBitmap *alien_bitmap;
static BitmapLayer *emoji_bitmap_layer;

static void main_window_load(Window *window){
  Layer *window_layer = window_get_root_layer(alien_main_window);
  GRect bounds = layer_get_bounds(window_layer);
  alien_bitmap = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_ALIEN);
  emoji_bitmap_layer = bitmap_layer_create(bounds);
  bitmap_layer_set_bitmap(emoji_bitmap_layer, alien_bitmap);
  layer_add_child(window_layer, bitmap_layer_get_layer(emoji_bitmap_layer));
}

static void main_window_unload(Window *window){
  bitmap_layer_destroy(emoji_bitmap_layer);
  gbitmap_destroy(alien_bitmap);
}

static void init(){
  alien_main_window = window_create();
  window_set_fullscreen(alien_main_window, true);
  window_set_background_color(alien_main_window, GColorBlack);
  window_set_window_handlers(alien_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload,
  });
  window_stack_push(alien_main_window, true);
}

static void deinit(){
   window_destroy(alien_main_window);
}

int main(){
  init();
  app_event_loop();
  deinit();
}
