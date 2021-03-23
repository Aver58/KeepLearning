//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <time.h>
//#include "QuadTree.h"
//
///**
// * ����Ԫ��
// * 1.�ж��Ƿ��ѷ��ѣ��ѷ��ѵ�ѡ���ʺϵ��ӽ�㣬���룻
// * 2.δ���ѵĲ鿴�Ƿ���أ����صķ��ѽ�㣬���²��룻
// * 3.δ���ص�ֱ�����
// *
// * @param node
// * @param ele
// * todo ʹ��Ԫ��ԭ��ַ���������·����ڴ���ɵ�Ч���˷�
// */
//void insertEle(struct QuadTreeNode* node, struct ElePoint ele) {
//    if (1 == node->is_leaf) {
//        if (node->ele_num + 1 > MAX_ELE_NUM) {
//            splitNode(node);
//            insertEle(node, ele);
//        }
//        else {
//            // todo �����أ������صĻ������ͬ�ĵ���Ŀ���� MAX_ELE_NUM�� ���������ѭ�����ѣ�
//            struct ElePoint* ele_ptr = (struct ElePoint*) malloc(sizeof(struct ElePoint));
//            ele_ptr->lat = ele.lat;
//            ele_ptr->lng = ele.lng;
//            strcpy_s(ele_ptr->desc, ele.desc);
//            node->ele_list[node->ele_num] = ele_ptr;
//            node->ele_num++;
//        }
//
//        return;
//    }
//
//    double mid_vertical = (node->region.up + node->region.bottom) / 2;
//    double mid_horizontal = (node->region.left + node->region.right) / 2;
//    if (ele.lat > mid_vertical) {
//        if (ele.lng > mid_horizontal) {
//            insertEle(node->RU, ele);
//        }
//        else {
//            insertEle(node->LU, ele);
//        }
//    }
//    else {
//        if (ele.lng > mid_horizontal) {
//            insertEle(node->RB, ele);
//        }
//        else {
//            insertEle(node->LB, ele);
//        }
//    }
//}
//
///**
// * ���ѽ��
// * 1.ͨ��������ȡ�ӽ�����Ⱥͷ�Χ
// * 2.�����ĸ���㣬���ص��������
// *
// * @param node
// */
//void splitNode(struct QuadTreeNode* node) {
//    double mid_vertical = (node->region.up + node->region.bottom) / 2;
//    double mid_horizontal = (node->region.left + node->region.right) / 2;
//
//    node->is_leaf = 0;
//    node->RU = createChildNode(node, mid_vertical, node->region.up, mid_horizontal, node->region.right);
//    node->LU = createChildNode(node, mid_vertical, node->region.up, node->region.left, mid_horizontal);
//    node->RB = createChildNode(node, node->region.bottom, mid_vertical, mid_horizontal, node->region.right);
//    node->LB = createChildNode(node, node->region.bottom, mid_vertical, node->region.left, mid_horizontal);
//
//    for (int i = 0; i < node->ele_num; i++) {
//        insertEle(node, *node->ele_list[i]);
//        free(node->ele_list[i]);
//        node->ele_num--;
//    }
//}
//
//struct QuadTreeNode* createChildNode(struct QuadTreeNode* node, double bottom, double up, double left, double right) {
//    int depth = node->depth + 1;
//    struct QuadTreeNode* childNode = (struct QuadTreeNode*) malloc(sizeof(struct QuadTreeNode));
//    struct Region* region = (struct Region*) malloc(sizeof(struct Region));
//    initRegion(region, bottom, up, left, right);
//    initNode(childNode, depth, *region);
//
//    return childNode;
//}
//
//void deleteEle(struct QuadTreeNode* node, struct ElePoint ele) {
//    /**
//     * 1.����Ԫ���б�ɾ����ӦԪ��
//     * 2.����ֵ�����Ԫ�������������������ʱ����ֵ�����
//     */
//}
//
//void combineNode(struct QuadTreeNode* node) {
//    /**
//     * �����ĸ������޵ĵ㣬��ӵ����޵��б�
//     * �ͷ������޵��ڴ�
//     */
//}
//
//void queryEle(struct QuadTreeNode node, struct ElePoint ele) {
//    if (node.is_leaf == 1) {
//        printf("��������%d�����ֱ��ǣ�\n", node.ele_num);
//        for (int j = 0; j < node.ele_num; j++) {
//            printf("%f,%f\n", node.ele_list[j]->lng, node.ele_list[j]->lat);
//        }
//        return;
//    }
//
//    double mid_vertical = (node.region.up + node.region.bottom) / 2;
//    double mid_horizontal = (node.region.left + node.region.right) / 2;
//
//    if (ele.lat > mid_vertical) {
//        if (ele.lng > mid_horizontal) {
//            queryEle(*node.RU, ele);
//        }
//        else {
//            queryEle(*node.LU, ele);
//        }
//    }
//    else {
//        if (ele.lng > mid_horizontal) {
//            queryEle(*node.RB, ele);
//        }
//        else {
//            queryEle(*node.LB, ele);
//        }
//    }
//}
//
//void initNode(struct QuadTreeNode* node, int depth, struct Region region) {
//    node->depth = depth;
//    node->is_leaf = 1;
//    node->ele_num = 0;
//    node->region = region;
//}
//
//void initRegion(struct Region* region, double bottom, double up, double left, double right) {
//    region->bottom = bottom;
//    region->up = up;
//    region->left = left;
//    region->right = right;
//}
//
//int TestQuadTree() {
//    struct QuadTreeNode root;
//    struct Region root_region;
//
//    struct ElePoint ele;
//    initRegion(&root_region, -90, 90, -180, 180);
//    initNode(&root, 1, root_region);
//
//    srand((int)time(NULL));
//    for (int i = 0; i < 100000; i++) {
//        ele.lng = (float)(rand() % 360 - 180 + (float)(rand() % 1000) / 1000);
//        ele.lat = (float)(rand() % 180 - 90 + (float)(rand() % 1000) / 1000);
//        insertEle(&root, ele);
//    }
//
//    struct ElePoint test;
//    test.lat = -24;
//    test.lng = -45.4;
//    queryEle(root, test);
//
//    return 0;
//}