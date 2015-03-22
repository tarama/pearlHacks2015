//import url(https://raw.githubusercontent.com/DmitryBaranovskiy/raphael/master/raphael.js);

//const INCREMENT = 1;
var window;

/*var card = new UI.Card();

main(){
var square;
square.attr("fill", "blue");
var across = 0;

function move(){
for(var i = 0; i < 144; i++){ //increments by 1 pixel(s) every iteration while object is still on screen
  across = square.x() + INCREMENT;
}
}
square.move();
}*/

//bitmap_layer_set_compositing_mode();
static GBitmap *alien_bitmap;
alien_bitmap = gbitmap_create_with_resource(IMAGE_ALIEN_EMOJI);
static BitmapLayer *emoji_bitmap_layer;
emoji_bitmap_layer = bitmap_layer_create(GRect(50, 50, 256, 256));//what should origin be?
bitmap_layer_set_bitmap(emoji_bitmap_layer, alien_bitmap);
layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(emoji_bitmap_layer));
gbitmap_destroy(alien_bitmap);
bitmap_layer_destroy(emoji_bitmap_layer);

