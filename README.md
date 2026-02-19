


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
## 3. Hướng dẫn thực thi (Execution Flow)

Để tái lập kết quả thử nghiệm, vui lòng chạy các tệp tin theo đúng thứ tự dưới đây. Quy trình được thiết kế đi từ bước khởi tạo dữ liệu đến tổng hợp báo cáo cuối cùng.

### Bước 1: Khởi tạo bộ dữ liệu
Chạy tệp `synthetic_sort_data.ipynb`.
* **Chức năng:** Sinh 10 dãy số (mỗi dãy 1 triệu phần tử) với `random_seed=42` để đảm bảo tính nhất quán.
* **Đầu ra:** Các tệp tin dữ liệu định dạng `.csv` chứa các dãy số thực và số nguyên theo các kịch bản (Tăng dần, Giảm dần, Ngẫu nhiên).

### Bước 2: Thực thi các thuật toán trên Python
Chạy tệp `Sort.ipynb`.
* **Chức năng:** Triển khai và đo thời gian thực thi của 4 phương pháp:
    1. **QuickSort** (Manual)
    2. **HeapSort** (Manual)
    3. **MergeSort** (Manual)
    4. **Numpy Sort** (Thư viện tối ưu)
* **Đầu ra:** Tệp result lưu trữ thời gian chạy của từng thuật toán trên các tập dữ liệu tương ứng.

### Bước 3: Thực thi thuật toán trên C++ (Đối chứng)
Biên dịch và chạy tệp `sort_cpp.cpp`.
* **Chức năng:** Sử dụng hàm `std::sort` của C++ để có thêm dữ liệu đối chiếu về hiệu năng giữa ngôn ngữ biên dịch (Compiled) và ngôn ngữ thông dịch (Interpreted).
* **Đầu ra:** Tệp lưu trữ thời gian thực thi của C++.

### Bước 4: Tổng hợp và Báo cáo
1. **Chạy tệp `merge.py`**:
   * **Chức năng:** Thu thập dữ liệu từ các tệp kết quả ở Bước 2 và Bước 3 để tạo ra tệp tổng hợp cuối cùng (`final_result`).
2. **Tệp Excel chứa bảng thống kê chi tiết và các biểu đồ so sánh trực quan (Bar Chart, Line Chart) về hiệu năng của tất cả các thuật toán.
3. **File báo cáo

---


