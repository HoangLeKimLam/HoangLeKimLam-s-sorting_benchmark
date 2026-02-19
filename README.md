


---

## 1. Giới thiệu tổng quan (Introduction)

Trong lý thuyết khoa học máy tính, các thuật toán sắp xếp như **QuickSort**, **MergeSort** hay **HeapSort** đều có độ phức tạp lý thuyết trung bình là $O(n \log n)$. Tuy nhiên, hiệu năng thực tế phụ thuộc rất lớn vào cách quản lý bộ nhớ, cách chọn pivot và đặc điểm của dữ liệu đầu vào.



### Mục tiêu dự án
* **Đánh giá hiệu năng thực tế:** So sánh thời gian thực thi của 3 thuật toán kinh điển so với `numpy.sort`và 'cpp_sort' (được tối ưu hóa bằng C-API).
* **Phân tích hành vi thuật toán:** Quan sát sự thay đổi về tốc độ khi dữ liệu thay đổi từ trạng thái "lý tưởng" sang "ngẫu nhiên" hoặc "ngược chiều".
* **Thử nghiệm quy mô lớn:** Chạy thực nghiệm trên tổng cộng **10 triệu phần tử**, vượt qua giới hạn của các bài toán quy mô nhỏ thông thường để thấy rõ sự khác biệt về hằng số thời gian.

---

## 2. Đặc điểm bộ dữ liệu (Dataset Specifications)

Để đảm bảo tính khách quan và bao quát, bộ dữ liệu thử nghiệm được thiết kế với tổng quy mô 10 triệu phần tử, chia thành các kịch bản khác nhau để "thử thách" từng thuật toán.

### Quy mô và Định dạng
* **Số lượng:** 12 dãy số độc lập.
* **Kích thước:** $10^6$ (1 triệu) phần tử mỗi dãy.
* **Kiểu dữ liệu (Data Types):** * **06 dãy số thực (float):** Kiểm tra khả năng xử lý dấu phẩy động.(1 tăng dần - 1 giảm dần - 4 random)
  * **06 dãy số nguyên (int):** Kiểm tra hiệu năng tính toán số nguyên thuần túy (1 tăng dần - 1 giảm dần - 4 random)
