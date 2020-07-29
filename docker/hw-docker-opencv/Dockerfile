# ---- Base (Dependencies) Image ----
FROM ubuntu:20.04 as base

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update \
    && apt-get install -y \
        build-essential \
        cmake \
        git \
        wget \
        unzip \
        yasm \
        pkg-config \
        python3 \
        python3-dev \
        python3-pip \
        libswscale-dev \
        libtbb2 \
        libtbb-dev \
        libjpeg-dev \
        libpng-dev \
        libtiff-dev \
        libavformat-dev \
        libpq-dev \
        libgtk2.0-dev \
    && rm -rf /var/lib/apt/lists/*

ADD requirements.txt /
RUN pip3 install -r requirements.txt

# ---- OpenCV Image ----
FROM base as dependencies

ENV OPENCV_VERSION="4.3.0"
RUN wget https://github.com/opencv/opencv/archive/${OPENCV_VERSION}.zip \
&& unzip ${OPENCV_VERSION}.zip \
&& mkdir /opencv-${OPENCV_VERSION}/cmake_binary \
&& cd /opencv-${OPENCV_VERSION}/cmake_binary \
&& cmake -DBUILD_TIFF=ON \
  -DBUILD_opencv_java=OFF \
  -DWITH_CUDA=OFF \
  -DWITH_GTK=ON \
  -DWITH_GTK_2_X=ON \
  -DWITH_OPENGL=ON \
  -DWITH_OPENCL=ON \
  -DWITH_IPP=ON \
  -DWITH_TBB=ON \
  -DWITH_EIGEN=ON \
  -DWITH_V4L=ON \
  -DBUILD_TESTS=OFF \
  -DBUILD_PERF_TESTS=OFF \
  -DCMAKE_BUILD_TYPE=RELEASE \
  .. \
&& make install \
&& rm /${OPENCV_VERSION}.zip \
&& rm -r /opencv-${OPENCV_VERSION}

# ---- Release Image ----
FROM dependencies as release

ADD . /
WORKDIR /

RUN mkdir build && cd build && cmake .. && make