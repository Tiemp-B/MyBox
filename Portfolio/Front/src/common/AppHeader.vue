<template>
    <header class="navbar">
        <!-- 왼쪽 타이틀 -->
        <div class="title" @click="scrollToTop">
            변재혁's Portfolio
        </div>

        <!-- 오른쪽 메뉴 -->
        <nav>
            <ul v-if="!isDropdown">
                <li v-for="menu in menus" :key="menu.name">
                    <a @click="scrollToSection(menu.target)">{{ menu.name }}</a>
                </li>
            </ul>
            <!-- 드롭다운 메뉴 -->
            <div v-else class="dropdown">
                <button @click="toggleDropdown">{{ dropdownVisible ? "Close" : "Menu" }}</button>
                <ul v-if="dropdownVisible">
                    <li v-for="menu in menus" :key="menu.name">
                        <a class="menu" @click="scrollToSection(menu.target)">{{ menu.name }}</a>
                    </li>
                </ul>
            </div>
        </nav>
    </header>
</template>

<script>
export default {
    name: "NavigationBar",
    data() {
        return {
            menus: [
                { name: "Home", target: "MyTitle" },
                { name: "About", target: "AboutMe" },
                { name: "Archives", target: "MyArchive" },
                { name: "Stacks", target: "MyStack" },
                { name: "Projects", target: "MyProject" },
            ],
            isDropdown: false,
            dropdownVisible: false,
        };
    },
    methods: {
        updateDropdownStatus() {
            this.isDropdown = window.innerWidth < 600;
        },
        toggleDropdown() {
            this.dropdownVisible = !this.dropdownVisible;
        },
        scrollToSection(targetId) {
            const section = document.getElementById(targetId);
            if (section) {
                section.scrollIntoView({ behavior: "smooth", block: "start" });
            }
        },
        scrollToTop() {
            window.scrollTo({ top: 0, behavior: "smooth" });
        },
    },
    mounted() {
        this.updateDropdownStatus();
        window.addEventListener("resize", this.updateDropdownStatus);
    },
    beforeUnmount() {
        window.removeEventListener("resize", this.updateDropdownStatus);
    },
};
</script>

<style scoped>

/* 네비게이션 바 스타일 */
.navbar {
    position: fixed;
    /* 화면에 고정 */
    top: 0;
    left: 0;
    width: 100%;
    /* 전체 폭 */
    display: flex;
    justify-content: space-between;
    align-items: center;
    padding: 0 1rem;
    background-color: #333;
    /* 배경색 */
    color: #fff;
    height: 70px;
    z-index: 1000;
    /* 다른 요소보다 위로 */
    box-shadow: 0px 4px 6px rgba(0, 0, 0, 0.2);
    /* 아래쪽 그림자 */
}

.title {
    font-size: 1.5rem;
    font-weight: bold;
    cursor: pointer;
}

/* 메뉴 스타일 */
nav ul {
    display: flex;
    list-style: none;
    margin-right: 25px;
    padding: 0;
}

nav ul li {
    margin: 0 0.5rem;
}

nav ul li a {
    color: #fff;
    text-decoration: none;
    cursor: pointer;
    transition: color 0.3s;
}

nav ul li a:hover {
    color: #ffea00;
}

/* 드롭다운 스타일 */
.dropdown {
    position: relative;
}

.dropdown button {
    background-color: #444;
    color: #fff;
    border: none;
    padding: 0.5rem 1rem;
    cursor: pointer;
}

.dropdown ul {
    position: absolute;
    top: 100%;
    left: 0;
    background-color: #444;
    list-style: none;
    margin: 0;
    padding: 0;
}

.dropdown ul li {
    padding: 0.5rem 1rem;
}

.dropdown ul li a {
    color: #fff;
    text-decoration: none;
    cursor: pointer;
    transition: color 0.3s;
}

.dropdown ul li a:hover {
    color: #ffea00;
}

/* 버튼 호버 시 밑줄 제거 */
a:hover {
    text-decoration: none;
}

a {
    font-size: 1.2rem;
}
</style>