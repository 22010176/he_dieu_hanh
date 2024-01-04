# Viết một chương trình Shell Script để xử lý tín hiệu hệ thống, chẳng hạn để tắt một tiến trình có pid đang chạy bằng lệnh kill.
# Thuật toán:
# Bước 1: Bắt đầu chương trình
# Bước 2: Đọc vào giá trị pid của tiến trình cần tắt.
# Bước 3: Sử dụng lệnh kill để tắt tiến trình có pid.
# Bước 4: Kết thúc chương trình.

#! /bin/sh
chmod +x Lap5.sh

echo "program for performing KILL operations"
ps -a

echo "enter the pid:"
read pid

kill -9 $pid

echo "finished"