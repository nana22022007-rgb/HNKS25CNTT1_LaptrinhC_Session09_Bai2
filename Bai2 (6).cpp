#include <stdio.h>
#include <string.h>

struct FlightTicket {
    char pnrCode[15];
    char passengerName[50];
    int ticketClass;
    float baggageWeight;
    float baggageFee;
};

int main() {
    struct FlightTicket danhSachVe[100];
    int soLuong = 0;
    int choice;

    do {
        printf("\n=== HE THONG BAN VE VA CHECK-IN MAY BAY ===\n");
        printf("1. Them ve may bay moi\n");
        printf("2. Hien thi danh sach ve\n");
        printf("3. Cap nhat hanh ly theo PNR\n");
        printf("4. Xoa ve theo PNR\n");
        printf("5. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (soLuong >= 100) {
                    printf("Danh sach ve da day, khong the them moi!\n");
                    break;
                }
                
                printf("Nhap ma PNR: ");
                scanf("%s", danhSachVe[soLuong].pnrCode);
                
                while (getchar() != '\n');
                
                printf("Nhap ho ten hanh khach: ");
                fgets(danhSachVe[soLuong].passengerName, sizeof(danhSachVe[soLuong].passengerName), stdin);
                size_t len = strlen(danhSachVe[soLuong].passengerName);
                if (len > 0 && danhSachVe[soLuong].passengerName[len - 1] == '\n') {
                    danhSachVe[soLuong].passengerName[len - 1] = '\0';
                }
                
                printf("Nhap hang ve (1-Eco, 2-Deluxe, 3-Business): ");
                scanf("%d", &danhSachVe[soLuong].ticketClass);
                
                printf("Nhap khoi luong hanh ly (kg): ");
                scanf("%f", &danhSachVe[soLuong].baggageWeight);
                
                if (danhSachVe[soLuong].ticketClass == 3) {
                    danhSachVe[soLuong].baggageFee = 0.0f;
                } else if (danhSachVe[soLuong].ticketClass == 1 || danhSachVe[soLuong].ticketClass == 2) {
                    if (danhSachVe[soLuong].baggageWeight <= 7.0f) {
                        danhSachVe[soLuong].baggageFee = 0.0f;
                    } else {
                        danhSachVe[soLuong].baggageFee = (danhSachVe[soLuong].baggageWeight - 7.0f) * 50000.0f;
                    }
                } else {
                    danhSachVe[soLuong].baggageFee = 0.0f;
                }
                
                printf("=> Them ve thanh cong! Cuoc phat hanh ly qua can: %.0f VND.\n", danhSachVe[soLuong].baggageFee);
                soLuong++;
                break;
            }
            case 2: {
                if (soLuong == 0) {
                    printf("Danh sach ve dang rong!\n");
                    break;
                }
                
                printf("\n========================================================================================\n");
                printf("STT | Ma PNR | Ho ten hanh khach | Hang ve | Hanh ly (kg) | Cuoc qua cuoc\n");
                printf("========================================================================================\n");
                for (int i = 0; i < soLuong; i++) {
                    char tenHang[20];
                    if (danhSachVe[i].ticketClass == 1) {
                        strcpy(tenHang, "Eco");
                    } else if (danhSachVe[i].ticketClass == 2) {
                        strcpy(tenHang, "Deluxe");
                    } else {
                        strcpy(tenHang, "Business");
                    }
                    printf("%d | %s | %s | %s | %.1f | %.0f VND\n", 
                           i + 1, 
                           danhSachVe[i].pnrCode, 
                           danhSachVe[i].passengerName, 
                           tenHang, 
                           danhSachVe[i].baggageWeight, 
                           danhSachVe[i].baggageFee);
                }
                printf("========================================================================================\n");
                break;
            }
            case 3: {
                if (soLuong == 0) {
                    printf("Danh sach ve dang rong!\n");
                    break;
                }
                
                char pnrInput[15];
                printf("Nhap ma PNR can cap nhat hanh ly: ");
                scanf("%s", pnrInput);
                
                int foundIndex = -1;
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(danhSachVe[i].pnrCode, pnrInput) == 0) {
                        foundIndex = i;
                        break;
                    }
                }
                
                if (foundIndex == -1) {
                    printf("Khong tim thay ve co ma PNR da nhap!\n");
                } else {
                    printf("Tim thay hanh khach: %s\n", danhSachVe[foundIndex].passengerName);
                    printf("Nhap trong luong hanh ly moi (kg): ");
                    scanf("%f", &danhSachVe[foundIndex].baggageWeight);
                    
                    if (danhSachVe[foundIndex].ticketClass == 3) {
                        danhSachVe[foundIndex].baggageFee = 0.0f;
                    } else if (danhSachVe[foundIndex].ticketClass == 1 || danhSachVe[foundIndex].ticketClass == 2) {
                        if (danhSachVe[foundIndex].baggageWeight <= 7.0f) {
                            danhSachVe[foundIndex].baggageFee = 0.0f;
                        } else {
                            danhSachVe[foundIndex].baggageFee = (danhSachVe[foundIndex].baggageWeight - 7.0f) * 50000.0f;
                        }
                    }
                    
                    printf("=> Cap nhat thanh cong! Phi hanh ly qua cuoc moi: %.0f VND.\n", danhSachVe[foundIndex].baggageFee);
                }
                break;
            }
            case 4: {
                if (soLuong == 0) {
                    printf("Danh sach ve dang rong!\n");
                    break;
                }
                
                char pnrInput[15];
                printf("Nhap ma PNR can xoa: ");
                scanf("%s", pnrInput);
                
                int foundIndex = -1;
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(danhSachVe[i].pnrCode, pnrInput) == 0) {
                        foundIndex = i;
                        break;
                    }
                }
                
                if (foundIndex == -1) {
                    printf("Khong tim thay ve co ma PNR da nhap!\n");
                } else {
                    for (int i = foundIndex; i < soLuong - 1; i++) {
                        danhSachVe[i] = danhSachVe[i + 1];
                    }
                    soLuong--;
                    printf("=> Da xoa thanh cong ve co ma PNR: %s ra khoi he thong.\n", pnrInput);
                }
                break;
            }
            case 5:
                printf("Cam on ban da su dung chuong trinh. Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai tu 1 den 5!\n");
        }
    } while (choice != 5);

    return 0;
}
