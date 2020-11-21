1. 请简述SkinnedMesh的实现原理。
1. 请简述Renderer的作用，并描述MeshRenderer与SkinnedMeshRenderer之间的关系 
与不同。

1. 请简述MeshRenderer中material和sharedmaterial的区别。
>- sharedMaterial 是共用的 Material，称为共享材质。修改共享材质会改变所用使用该材质的物体，并且编辑器中的材质设置也会改变。
>- material 是独立的 Material，返回分配给渲染器的第一个材质。修改材质仅会改变该物体的材质。如果该材质被其他的渲染器使用，将克隆该材质并用于当前的渲染器。

1. https://blog.csdn.net/f_957995490/article/details/108783509