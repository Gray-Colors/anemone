
CFLAGS = -std=c17 -O2 #-ANEMONE_PLATFORM_LINUX
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

VulkanTest: *.c *.h
	gcc $(CFLAGS) -o VulkanTest *.c *.h $(LDFLAGS)



.PHONY: make clean

test: VulkanTest
	./VulkanTest

clean:
	rm -f VulkanTest
