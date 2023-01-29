//
// Created by longdnk on 12/25/2022.
//
#include <bits/stdc++.h>

using namespace std;

int Fibo(int n) {
    if (n == 1 || n == 2) return 1;
    return Fibo(n - 2) + Fibo(n - 1);
}
// ~ 2 ^ n (1,67 ^ n => 1,7 ^ n)

int Tribo(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    }
    return Tribo(n - 1) + Tribo(n - 2) + Tribo(n - 3);
}
// 3 ^ n (2, 87 ^ n)

// Fibo + Tribo => n = 50 đứng máy !!!!

int checkEven(int x) {
    if (x % 2 == 0) {
        return 1;
    }
    return 0;
}

bool isPrime(int x) {
    if (x < 2) return true;
    for (int i = 2; i * i <= x; i = i + (i & 1) + 1)
        if (!(x % i))
            return false;
    return true;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // tên hàm và tên biến => camelCase ví dụ: helloWorld, chaoEmAnhDungDayTuChieu, ...
    // tên hàm và biến phải có nghĩa, tránh đặt tên theo bảng chữ cái, không đặt quá dài, hạn chế ghi tắt !!!.
    // 1 module hoặc là 1 hàm xử lý tính toán có thể có hiều hàm con khác nhau, nhưng quy chung lại là 1 hàm không được dùng quá 2 return.
    // với các vòng lặp thì hạn chế dùng 2 for, nếu buộc dùng thì phải cẩn thận + ràng buộc được số bước lặp trong trường hợp xấu nhất.
    // hạn chế dùng dạng đệ quy khi viết, nhất là dạng đệ quy phân rã => đệ quy nhị phân (tính fibo đệ quy), đệ quy tam phân (tính tribo).
    // khi viết code, lưu ý 1 file không quá 1200 dòng, 1 dòng không vượt quá 160 ký tự.
    // khi dùng if else, với các hàm có 2 trường hợp có thể ưu tiên if else nhị phân, nếu được loại bỏ luôn else, chỉ ưu tiên if tránh gây loãng chương trình
    // tối ưu + tối giản các câu lệnh điều kiện.
    // đối với js thì ưu tiên phép so sánh === hơn là phép ==
    // với phép xử lý ra 1 biến theo logic thì luôn để 1 giá trị mặc định cho biến.
    // khi dùng phép căn bậc 2 nên là number * number <= x;
    // ưu tiên dùng các arrow function hơn là dùng function raw, một số trường hợp buộc dùng raw function thì mới dùng
    // dùng các biến cục bộ thay cho toàn cục, chỉ dùng toàn cục với các phần như redux và vài biến xử lý thông thường, tránh dùng biến toàn cục cho phép logic.
    // khi dùng biến toàn cục cho các phép logic, luôn kiểm tra kỹ khi xử lý, tránh gây hiệu ứng lề.
    // với js thì luôn dùng 2 biết const và let, tránh dùng var.
    // khi sử dụng phép đặt cờ sử dụng 4 con số huyền thoại: 1e9, -1e9, 1e18, -1e18
    // sử dụng các phép thao tác bit nếu có thể, nắm chắc logic khi sử dụng
    // linh động và luôn sử dụng cú pháp tuân theo es6 trở lên
    // tìm hiểu và sử dụng, nắm bắt các cấu trúc dữ liệu cho phù hợp, với c++ luôn đa dạng khi có list, vector, map, unordered_map, struct, ... còn riêng js thì chỉ
    // tồn tại duy nhất 1 kiểu là json
    // chỉ giữ lại các console log cần thiết, tránh trường hợp cái nào cũng console log
    // quản lý bộ nhớ, tránh khai các biến trong dòng for, => stack overflow
}