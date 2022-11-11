# Computer-Vision-OpenCV


rstly, we opened the dark room laser spot video. Then read the new frame from 
video and, we have applied following on each frame of the video:
1. We declared the vector of the mat object to store the output of the split () 
function

2. Applied the split () function on frame which separate the channels in a 
multichannel array into multiple single channel arrays.it will store the 
blue channel image at location 0, green at location 1 and red at location 
2 in the vector. Usually, we think of images in the RGB color space — the 
red pixel first, the green pixel second, and the blue pixel third. However, 
OpenCV stores RGB images in reverse channel order. Instead of storing an 
image in RGB order, it stores the image in BGR order.

3. After doing the split we will write the image using inwrite(name,bgr[1]) (here 
the bgr is vector of the single channel) because the video contains no green 
color hence bgr[1] will give us grayscale frame which we will store in the 
.pgm format ( the .pgm format stores the gray color images only) 

4. Moreover, we have used the counter to keep track of the frame numbers.

To store the video, we have used 2 methods:
1. Using ffmpeg: we have stored the images in name%d.pgm format and the used 
command to store video in MPEG4 format. We got total 1260 frames and we 
converted it to the video of 30 fps so that we will get the output video time same as 
input.

2.Using OpenCV (stored in Capture2B.cpp): we made another code and it is saved 
as capture2B.cpp. in this code we have used the videoWriter to write the video 
instead of saving the frames in folder. This method is straightforward, we did the 
same operations as above on the frame. But we did not write all the frames into a 
pgm file, instead we used the video writer object to store all the frames.

Firstly, we created and initialized the VideoWriter object 

For instance:
VideoWriter oVideoWriter ("/home/manavi/Documents/ass5/Output.mp4", 
VideoWriter::fourcc('M','J','P','G'),frames_per_second,Size(frame_width,frame_hei
ght), 0);

Here first parameter is path to store the output video, second is codec, third is fps, 
fourth is size of frame, last one is important one which is iscolor=false because we 
are saving the gray image not color image.

Lastly, we have wrote each frame using oVideoWriter.write(). And at the end we 
got an output video 

At specified location. If we press esc at any time or frame then we will get video 
up to that time or frame.
